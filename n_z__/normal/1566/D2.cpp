#include<bits/stdc++.h>
using namespace std;
#define int long long
using namespace std;
int a[90001];
pair<int,bool>fk[90001];
#define b first
#define c second
map<int,int>m;
main(){
	int t;cin>>t;
	while(t--){
		m.clear();
		int n,mm;
		cin>>n>>mm;
		for(int x=1;x<=n*mm;x++) cin>>a[x],fk[x].b=a[x],fk[x].c=false;
		sort(a+1,a+n*mm+1);
        int ans=0;
		for(int x=1;x<=n*mm;x++){
			if(!m[fk[x].b]){
				auto f=lower_bound(a+1,a+n*mm+1,fk[x].b);
				while((f-a)%mm&&*f==fk[x].b)f++;
				if(*f!=fk[x].b)f--;
                int g=f-a;
                for(int y=(g-1)/mm*mm+1;y<=g;y++)ans+=fk[y].c;
			    fk[g].c=1;
			    m[fk[x].b]=g;
			}
			else{
				auto f=m[fk[x].b]-1;
				while(f%mm&&fk[f].c&&a[f]==fk[x].b)f--;
				if(a[f]!=fk[x].b||f%mm==0){
                    f=(f/mm+1)*mm+1;
                    while(a[f]==fk[x].b&&f%mm!=0)f++;
                    f-=(a[f]!=fk[x].b);
				}
                for(int y=(f-1)/mm*mm+1;y<=f;y++)ans+=fk[y].c;
			    fk[f].c=1;
			    m[fk[x].b]=f;
			}
		}
		cout<<ans<<endl;
	}
}