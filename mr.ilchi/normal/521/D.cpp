#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100000+10;

int k,n,m;
int a[MAXN],type[MAXN];
pair<int,int> f0[MAXN];
vector< pair<int,int> > f1[MAXN];

struct frac{
	long long a,b,who;
	frac () { a=0, b=1, who=-1; }
	frac (long long a, long long b, int who) : a(a), b(b), who(who) {}
	bool operator < (const frac &B) const{
		return (long double)a * (long double)B.b < (long double)B.a * (long double)b; 
	}
};

int main(){
	scanf("%d%d%d", &k, &n, &m);
	for (int i=0; i<k; i++)
		scanf("%d", &a[i]);
	vector<frac> have;
	for (int i=0; i<n; i++){
		int pos, val;scanf("%d%d%d", &type[i], &pos, &val);
		pos--;
		if (type[i]==1){
			f0[pos] = max(f0[pos], pair<int,int>(val,i));
		}else if (type[i]==2)
			f1[pos].push_back(pair<int,int>(val,i));
		else
			have.push_back(frac(val,1,i));
	}
	for (int i=0; i<k; i++){
		sort(f1[i].begin(), f1[i].end(), greater < pair<int,int> > ());
		long long cur = a[i];
		bool flag = false;
		for (int j=0; j<(int)f1[i].size(); j++){
			if (!flag && a[i]<f0[i].first && f1[i][j].first<f0[i].first-a[i]){
				have.push_back(frac(cur+f0[i].first-a[i],cur,f0[i].second));
				cur+= f0[i].first-a[i];
				flag = true;
			}
			have.push_back(frac(cur+f1[i][j].first,cur,f1[i][j].second));
			cur+= f1[i][j].first;
		}
		if (!flag && a[i]<f0[i].first)
			have.push_back(frac(cur+f0[i].first-a[i],cur,f0[i].second));
	}
	sort(have.begin(), have.end()); 
	vector< pair<int,int> > ans;
	for (int i=(int)have.size()-1; i>=0 && m; i--, m--)
		ans.push_back(pair<int,int>(type[have[i].who], have[i].who));
	sort(ans.begin(), ans.end());
	printf("%d\n", (int)ans.size());
	for (int i=0; i<(int)ans.size(); i++)
		printf("%d ", ans[i].second+1);
	puts("");
	return 0;
}