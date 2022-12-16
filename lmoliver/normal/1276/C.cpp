#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define F(N,S,E) for(int N=(int)S;N<=(int)E;i++)
typedef map<int,int> M;
M mp;
const int N=400400;
int cnts[N];
int res[N];
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	F(i,1,n){
		int x;
		cin>>x;
		mp[x]++;
	}
	for(M::iterator it=mp.begin();it!=mp.end();it++){
		cnts[it->second]++;
	}
	int ans=0;
	int row=-1;
	int tot=n;
	for(int i=n;i>=1;i--){
		int cnt=cnts[i+1];
		cnts[i]+=cnt;
		tot-=cnt;
		// cerr<<i<<" "<<tot<<endl;
		if(tot>=(LL)i*i){
			int tans=tot/i*i;
			if(tans>ans){
				ans=tans;
				row=i;
			}
		}
	}
	cout<<ans<<endl;
	int col=ans/row;
	cout<<row<<" "<<col<<endl;
	int ind=0;
	vector<int> v(ans);
	for(M::iterator it=mp.begin();it!=mp.end();it++){
		int w=min(it->second,row);
		if(w==row)while(w--){
			v[ind++]=it->first;
			if(ind==ans)goto ok;
		}
	}
	for(M::iterator it=mp.begin();it!=mp.end();it++){
		int w=min(it->second,row);
		if(w!=row)while(w--){
			v[ind++]=it->first;
			if(ind==ans)goto ok;
		}
	}
	ok:;
	ind=0;
	for(int j=0;j<col;j++){
		for(int i=0;i<row;i++){
			res[i*col+(i+j)%col]=v[ind++];
		}
	}
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			printf("%d ",res[i*col+j]);
		}
		printf("\n");
	}
	return 0;
}