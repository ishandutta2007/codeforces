#include <bits/stdc++.h>
using namespace std;
#define modulo 998244353
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000000000

int main(){
	
	int n,sx,sy;
	cin>>n>>sx>>sy;
	
	vector<pair<int,pair<int,int>>> V(4,make_pair(0,make_pair(0,0)));
	V[0].second = make_pair(sx+1,sy);
	V[1].second = make_pair(sx-1,sy);
	V[2].second = make_pair(sx,sy+1);
	V[3].second = make_pair(sx,sy-1);
	
	for(int i=0;i<n;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		
		if(x>sx)V[0].first++;
		if(x<sx)V[1].first++;
		if(y>sy)V[2].first++;
		if(y<sy)V[3].first++;
	}
	
	sort(V.begin(),V.end());
	reverse(V.begin(),V.end());
	
	for(int i=0;i<4;i++){
		int x = V[i].second.first;
		int y = V[i].second.second;
		if(x<0||x>1000000000||y<0||y>1000000000)continue;
		cout<<V[i].first<<endl;
		cout<<x<<' '<<y<<endl;
		return 0;
	}
	
	return 0;
}