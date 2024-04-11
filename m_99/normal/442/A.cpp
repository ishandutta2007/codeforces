#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000



int main(){
	
	int n;
	cin>>n;
	
	vector<string> s(n);
	rep(i,n)cin>>s[i];
	
	string c = "RGBYW";
	rep(i,n){
		rep(j,c.size()){
			if(c[j]==s[i][0])s[i][0] = '1'+j;
		}
	}
	
	vector<pair<int,int>> p(n);
	rep(i,n){
		p[i].first = s[i][0]-'1';
		p[i].second = s[i][1]-'1' + 5;
	}
	
	int ans = 100;
	
	rep(i,1<<10){
		bool f = true;
		rep(j,n){
			int x = p[j].first,y = p[j].second;
			if((i>>x)&1){
				if((i>>y)&1)continue;
			}
			for(int k=j+1;k<n;k++){
				int z = p[k].first,w = p[k].second;
				if((i>>z)&1){
					if((i>>w)&1)continue;
				}
				if(p[j]==p[k])continue;
				
				
				
				int xx = (i>>x)&1, yy = (i>>y)&1;
				int zz = (i>>z)&1,ww = (i>>w)&1;
				
				if(x==z){
					if(!yy&&!ww)f=false;
				}
				else if(y==w){
					if(!xx&&!zz)f=false;
				}
				else{
					if(!xx&&!yy&&!ww&&!zz)f=false;
				}
				
				
				
			}
			if(!f)break;
		}
		if(!f)continue;
		int cc = 0;
		rep(j,10){
			if((i>>j)&1)cc++;
		}

		ans = min(ans,cc);
	}
	
	cout<<ans<<endl;
	
    return 0;
}