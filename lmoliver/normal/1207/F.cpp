#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=500000;
const int S=700;
LL a[N+55]={0};
vector<LL> rem[S+77];
int main(){
	for(int i=1;i<=S;i++){
		for(int j=0;j<i;j++){
			rem[i].push_back(0);
		}
	}
	int q;
	scanf("%d",&q);
	while(q--){
		int t,x,y;
		scanf("%d%d%d",&t,&x,&y);
		if(t==1){
			a[x]+=y;
			for(int i=1;i<=S;i++){
				rem[i][x%i]+=y;
			}
		}
		else if(t==2){
			LL ans;
			if(x<=S){
				ans=rem[x][y];
			}
			else{
				ans=0;
				for(int i=0;i+y<=N;i+=x){
					ans+=a[i+y];
				}
			}
			printf("%lld\n",ans);
		}
		else{
			cerr<<"QAQ?"<<endl;
		}
	}
	return 0;
}