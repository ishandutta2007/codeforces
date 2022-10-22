#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000

int main(){
	
	int t;
	cin>>t;
	
	for(int _=0;_<t;_++){
		int n,m;
		scanf("%d %d",&n,&m);
		vector<vector<int>> a(n,vector<int>(m));
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				scanf("%d",&a[i][j]);
			}
		}
		bool f = true;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				bool F1 = (i==0||i==n-1);
				bool F2 = (j==0||j==m-1);
				if(F1&&F2){
					if(a[i][j]>2)f=false;
					else a[i][j]=2;
				}
				else if(F1||F2){
					if(a[i][j]>3)f=false;
					else a[i][j]=3;
				}
				else{
					if(a[i][j]>4)f=false;
					else a[i][j]=4;
				}
			}
		}
		if(!f){
			printf("NO\n");
			continue;
		}
		else{
			printf("YES\n");
			for(int i=0;i<n;i++){
				for(int j=0;j<m;j++){
					if(j!=0)printf(" ");
					printf("%d",a[i][j]);
				}
				printf("\n");
			}
		}
	}
		
	return 0;
}