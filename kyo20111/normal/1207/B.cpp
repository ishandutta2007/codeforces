#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,a[55][55],b[55][55];
vector<pair<int,int>> v;
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) scanf("%d",&a[i][j]);

    for(int i=n;i>=1;i--){
    	for(int j=m;j>=1;j--){
    		if(a[i][j]){
    			if(i==1 || j==1 || !a[i-1][j] || !a[i][j-1] || !a[i-1][j-1]){
    				if(b[i][j]) continue;
    				return !printf("-1");
    			}
    			v.push_back({i-1,j-1});
    			b[i-1][j-1]=b[i-1][j]=b[i][j-1]=b[i][j]=1;
    		}
    	}
    }
    printf("%d\n",(int)v.size());
    for(auto nxt : v) printf("%d %d\n",nxt.first,nxt.second);
}