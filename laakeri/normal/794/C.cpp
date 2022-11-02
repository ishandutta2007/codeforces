#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

char ans[303030];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s1,s2;
	cin>>s1>>s2;
	sort(s1.begin(), s1.end());
	sort(s2.rbegin(), s2.rend());
	int n=s1.size();
	int u2=n/2;
	int u1=n-u2;
	s1.resize(u1);
	s2.resize(u2);
	int p1=0;
	int p2=0;
	int si1=0;
	int si2=n-1;
	int t=0;
	for (int i=0;i<n;i++){
		t=i;
		if (i==n-1){
			if (i%2==0){
				ans[si1]=s1[p1];
			}
			else{
				ans[si1]=s2[p2];
			}
			continue;
		}
		if (i%2==0){
			if (s1[p1]<s2[p2]){
				ans[si1]=s1[p1];
				si1++;
				p1++;
			}
			else break;
		}
		else{
			if (s2[p2]>s1[p1]){
				ans[si1]=s2[p2];
				si1++;
				p2++;
			}
			else break;
		}
	}
	int le=n-si1;
	if (le%2==0){
		t^=1;
	}
	while (si1<n){
		if (t%2==0){
			assert(p1<(int)s1.size());
			ans[si1]=s1[p1];
			p1++;
		}
		else{
			assert(p2<(int)s2.size());
			ans[si1]=s2[p2];
			p2++;
		}
		si1++;
		t++;
	}
	string v;
	for (int i=0;i<n;i++){
		v+=ans[i];
	}
	cout<<v<<endl;
}