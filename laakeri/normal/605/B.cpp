#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef long double ld;

int v1[101010];
int v2[101010];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	vector<pair<pair<int, int>, int> > lol(m);
	for (int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		lol[i]={{a, 1-b}, i};
	}
	sort(lol.begin(), lol.end());
	int fes=0;
	int s=0;
	int tv1=3;
	int tv2=1;
	for (int i=0;i<m;i++){
		if (lol[i].F.S==1){
			if (fes==0){
				cout<<-1<<endl;
				return 0;
			}
			else{
				v1[lol[i].S]=tv1;
				v2[lol[i].S]=tv2;
				tv2--;
				fes--;
				if (tv2==0){
					tv1++;
					tv2=tv1-2;
				}
			}
		}
		else{
			if (i>0){
				v1[lol[i].S]=s;
				v2[lol[i].S]=s+1;
				fes+=s-1;
				s++;
			}
			else{
				v1[lol[i].S]=1;
				v2[lol[i].S]=2;
				s+=2;
			}
		}
	}
	for (int i=0;i<m;i++){
		cout<<v1[i]<<" "<<v2[i]<<'\n';
	}
}