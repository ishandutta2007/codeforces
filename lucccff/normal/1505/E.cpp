#include <bits/stdc++.h>
using namespace std;

int main(){
    int i,j,k,l,m,n,x,y,s,r,t,f;
    int a[10][10];
    char ch;
    cin>>n>>k;
    for(i=0;i<n;i++) {
        getchar();
        for(j=0;j<k;j++){
            if (getchar()=='*') a[i][j]=1;
            else a[i][j]=0;
        }
    }
    f=0;
    x=y=0;
    if (n*k==0) {
    	cout<<0;
    	return 0;
	}
    if (a[x][y]==1) s=1;
    else s=0;
    while (f==0) {
        f=1;
        for(i=1;i<10;i++) {
            if (i+y<k) j=i+y;
            else if (i+y+x<n+k-1) j=k-1;
            else break;
            t=x+y+i-j;
            while ((j>=y)&&(t<n)) {
                if (a[t][j]==1) {
                    x=t;
                    y=j;
                    f=0;
                    s++;
                    break;
                }
                t++;
                j--;
            }
            if (f==0) break;
        }
    }
    cout<<s;
    return 0;
}