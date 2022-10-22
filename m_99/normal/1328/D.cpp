#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x)+modulo)%modulo)
#define Inf 1000000000000


int main() {

	int t;
	cin>>t;
	
	for(int _=0;_<t;_++){
		int n;
		cin>>n;
		vector<int> a(n);
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		
		vector<int> ans(n,1);
		for(int i=1;i<n;i++){
			if(a[i]==a[i-1])ans[i]=ans[i-1];
			else{
				if(ans[i-1]==1)ans[i]=2;
				else ans[i]=1;
			}
		}
		
		if(a.back()!=a[0]){
			if(ans[0]==ans.back()){
				bool f = false;
				for(int i=1;i<n;i++){
					if(f&&a[i]==a[i-1])ans[i]=ans[i-1];
					else{
						if(ans[i-1]==1)ans[i]=2;
						else ans[i]=1;
						if(a[i]==a[i-1])f=true;
					}
				}
				if(!f)ans.back()=3;
			}
		}
		
		int m = 0;
		for(int i=0;i<n;i++)m = max(m,ans[i]);
		cout<<m<<endl;
		
		for(int i=0;i<n;i++){
			if(i!=0)printf(" ");
			printf("%d",ans[i]);
		}
		printf("\n");
	}

    return 0;
}