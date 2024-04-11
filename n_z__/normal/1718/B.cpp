#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
map<int,int> fst,lst,cnt;
int f[50],pre[50];
signed main(){
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	f[0]=f[1]=pre[0]=1; pre[1]=2;
	for(int i=2;i<=44;i++){
		f[i]=f[i-1]+f[i-2];
		pre[i]=pre[i-1]+f[i];
	}
	pre[45]=1e14;
	int t;
	cin>>t;
	while(t--){
		int k;
		cin>>k;
		int c[k+1],tot=0;
		priority_queue<pair<int,int> > pq; 
		for(int i=1;i<=k;i++){
			cin>>c[i];
			tot+=c[i];
			pq.push(make_pair(c[i],i));
		}
		if(pre[lower_bound(pre,pre+46,tot)-pre]!=tot){
			cout<<"NO"<<endl;
			continue;
		}
		int now=lower_bound(pre,pre+46,tot)-pre;
		int ok=1,lst=0,nowc=0;
		while(now>=0&&!pq.empty()){
			pair<int,int> l=pq.top();
			pq.pop();
			if(l.second==lst){
				ok=0;
				cout<<"NO"<<endl;
				break;
			}
			if(l.first<f[now]){
				ok=0;
				cout<<"NO"<<endl;
				break;
			}
			pq.push(make_pair(l.first-f[now],nowc));
			lst=nowc;
			now--;
			nowc--;
		}
		if(ok){
			cout<<"YES"<<endl;
		}
	}
	return 0;
}
/*
5 3 5 4 3 4
things to check
1.  int overflow or long long memory need
2.  recursion/array/binary search/dp/loop bounds
3.  precision
4.  special cases(n=,bounds)
5.  delete debug statements
6.  initialize(especially multi-tests)
7.  = or == , n or m ,++ or -- , i or j , > or >= , < or <= , - or =
8.  keep it simple and stupid
9.  do not delete, use // instead
10. operator priority
11. is there anything extra to output?
12. if you don't know where the bug is , try to clear some parts of the code
 and check each part seperately.
*/