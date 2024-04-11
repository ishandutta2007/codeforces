#include <bits/stdc++.h>
#define a first
#define b second
#define pb push_back
using namespace std;
#define endl '\n'
typedef long long llo;

llo it[2][200001];
llo ma[2][200001];
llo ma2[2][200001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo t;
	cin>>t;
	while(t--){
		llo n;
		cin>>n;
		for(llo i=0;i<2;i++){
			for(llo j=0;j<n;j++){
				cin>>it[i][j];
			}
		}
		for(llo j=n-1;j>=0;j--){
			for(llo i=0;i<2;i++){
				ma[i][j]=it[i][j]-j;
				if(j<n-1){
					ma[i][j]=max(ma[i][j],ma[i][j+1]);
				}
				ma2[i][j]=it[i][j]-(n-1-j);
				if(j<n-1){
					ma2[i][j]=max(ma2[i][j],ma2[i][j+1]);
				}
			}
		}
		pair<llo,llo> cur={0,0};
		llo su=-1;
		llo ans=2e9;
		while(true){

			su=max(su+1,it[cur.a][cur.b]+1);
			if(cur.a==0 and cur.b==0){
				su=0;
			}
			if(cur.b%2==0 and cur.a==1){
				if(cur.b==n-1){
					ans=min(ans,su);
					break;
				}
				llo cur2=su;
				cur2+=(n-1-cur.b)*2;
				llo ax=ma[1][cur.b+1]-su+cur.b;
				llo bx=ma2[0][cur.b+1]-(n-1-cur.b)-1-su;
				ax++;
				bx++;

				if(ax<0){
					ax=0;
				}
				if(bx<0){
					bx=0;
				}
				cur2+=max(ax,bx);
				ans=min(ans,cur2);

				cur.b++;
			}
			else if(cur.b%2==1 and cur.a==0){
				if(cur.b==n-1){
					ans=min(ans,su);
					break;
				}

				llo cur2=su;
				cur2+=(n-1-cur.b)*2;
				llo ax=ma[0][cur.b+1]-su+cur.b;
				llo bx=ma2[1][cur.b+1]-(n-1-cur.b)-1-su;
				ax++;
				bx++;
				//cout<<ax<<":"<<bx<<endl;
				if(ax<0){
					ax=0;
				}
				if(bx<0){
					bx=0;
				}
				cur2+=max(ax,bx);
				ans=min(ans,cur2);
				//cout<<cur.a<<":"<<cur.b<<":"<<cur2<<":"<<su<<endl;
				cur.b++;
			}
			else{
				cur.a^=1;
			}
		}
		llo zz=0;
		for(llo i=0;i<n;i++){
			if(i==0){
				continue;
			}
			zz=max(zz,it[0][i]-(i)+1);
		}
		for(llo i=n-1;i>=0;i--){
			zz=max(zz,it[1][i]-(n-1)-(n-i)+1);
		}
		zz+=2*n-1;
		ans=min(ans,zz);
		cout<<ans<<endl;

	}








	return 0;
}