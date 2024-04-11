//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second

llo ask(llo i,llo j){
	cout<<"? "<<i<<" "<<j<<endl;
	llo xx;
	cin>>xx;
	return xx;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo t;
	cin>>t;
	while(t--){
		llo n;
		cin>>n;
		llo x=ask(1,n);
		llo low=1;
		llo high=n;
		while(low<high){
			llo mid=(low+high)/2;
			llo xx=ask(1,mid);
			if(xx==0){
				low=mid+1;
			}
			else if(xx==x){
				high=mid;
			}
			else{
				llo yy=ask(1,mid+1);
				llo pp=yy-xx-1;
				llo su=((yy-xx)*(yy-xx+1))/2;
				if(su==yy and yy!=xx){
					llo ii=mid+1-(yy-xx);
					llo low2=ii;
					for(llo j=30;j>=0;j--){
						if(low2+(1LL<<j)<=high){
							llo zz=ask(1,low2+(1LL<<j));
							if(((low2+(1LL<<j)-ii)*(low2+(1LL<<j)-ii+1))/2==zz){
								low2+=(1LL<<j);
							}
						}
					}
					llo jj=low2+1;
					llo zz=ask(1,jj);
					llo oy=sqrt(x*2-zz*2);
					llo kk=jj+oy;
					cout<<"! "<<ii<<" "<<jj<<" "<<kk<<endl;
					break;

				}
				else{
					llo jj=mid-pp;
					if(yy==xx){
						jj=mid+1;
					}
					llo zz=ask(1,jj);
					llo ox=sqrt(zz*2);
					llo ii=jj-ox-1;
					llo oy=sqrt(x*2-zz*2);
					llo kk=jj+oy;
					cout<<"! "<<ii<<" "<<jj<<" "<<kk<<endl;
					break;
				}
			}
		}

	}





 
	return 0;
}