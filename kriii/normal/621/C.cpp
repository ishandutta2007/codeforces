#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> fact;
int n,p;

void add(int x)
{
	fact.push_back(x);
}

int l[100010],r[100010];

int main()
{
	scanf ("%d %d",&n,&p);

	for (int i=1;i*i<=p;i++) if (p % i == 0){
		add(i);
		if (i * i != p) add(p/i);
	}
	sort(fact.begin(),fact.end());

	for (int i=0;i<n;i++) scanf ("%d %d",&l[i],&r[i]);
	l[n] = l[0];
	r[n] = r[0];
	double ans = 0;
	for (int k=0;k<n;k++){
		vector<int> d(fact.size());
		for (int i=fact.size()-1;i>=0;i--){
			d[i] = r[k] / fact[i] - (l[k] - 1) / fact[i];
			for (int j=i+1;j<fact.size();j++) if (fact[j] % fact[i] == 0) d[i] -= d[j];
		}

		double now = 0;
		for (int i=0;i<fact.size();i++){
			int rp = p / fact[i];
			now += (long long)d[i] * (r[k+1] / rp - (l[k+1] - 1) / rp);
		}
		now /= r[k] - l[k] + 1;
		now /= r[k+1] - l[k+1] + 1;
		ans += now;
	}
	printf ("%.12lf\n",ans*2000);

	return 0;
}