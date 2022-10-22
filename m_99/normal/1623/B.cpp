#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define Inf 1000000001

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n;
		cin>>n;
		
		vector<pair<int,pair<int,int>>> p;
		rep(i,n){
			int l,r;
			cin>>l>>r;
			l--;
			p.emplace_back(r-l,make_pair(l,r));
		}
		
		vector<int> l,r,d;
		vector<bool> f(n,false);
		sort(p.begin(),p.end());
		//cout<<'a'<<endl;
		rep(i,n){
			int ll = p[i].second.first,rr = p[i].second.second;
			//cout<<ll<<','<<rr<<endl;
			for(int j=ll;j<rr;j++){
				if(f[j]==false){
					f[j] = true;
					l.push_back(ll+1);
					r.push_back(rr);
					d.push_back(j+1);
					break;
				}
			}
		}
		
		reverse(l.begin(),l.end());
		reverse(r.begin(),r.end());
		reverse(d.begin(),d.end());
		rep(i,n){
			printf("%d %d %d\n",l[i],r[i],d[i]);
		}
			
	}
	
	return 0;
}