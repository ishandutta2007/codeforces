#include<bits/stdc++.h>
using namespace std;
int lst[101],ans1[101],ans2[101];
int main(){
    int n,k;
    cin>>n>>k;
    for(int x=1;x<=n*k;x++)
    {
        int z;
        cin>>z;
		if(lst[z]<=n*k&&lst[z]){
			ans1[z]=lst[z],ans2[z]=x;
			lst[z]=n*k+1;
            int q=z-1-(z-1)%(k-1);
			for(int y=q+1;y<k+q;y++)
			if(lst[y]<=n*k)lst[y]=0;
		}
		else lst[z]=max(lst[z],x);
	}
	for(int x=1;x<=n;x++)
    cout<<ans1[x]<<' '<<ans2[x]<<endl;
}