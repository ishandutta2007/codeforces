

    #include<bits/stdc++.h>
    using namespace std;
    int n,a[310000],b[310000],dis[310000],lst[310000];
    vector<int> vec;
    int main(){
    	scanf("%d",&n);
    	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    	for (int i=1;i<=n;i++) scanf("%d",&b[i]);
    	for (int i=n,j=n-1;i>=1;i--){
    		int x=i+b[i];
    		while (j>=x-a[x]){
    			dis[j]=dis[i]+1;
    			lst[j]=i; j--;
    		}
    		if (j==i-1){
    			puts("-1");
    			return 0;
    		}
    	}
    	
    	int u=0;
    	while (u!=n) vec.push_back(u),u=lst[u];
    	reverse(vec.begin(),vec.end());
    	printf("%d\n",dis[0]);
    	for (int v:vec) printf("%d ",v);
    	return 0;
    }