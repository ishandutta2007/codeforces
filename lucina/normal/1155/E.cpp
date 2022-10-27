#include<bits/stdc++.h>
using namespace std;
int tmp,ma,a[20][20],n,ans[20],y;
const int maxn=3e5+10,mod=1e6+3;
int add(int a, int b) {
  a += b;
  if (a >= mod) a -= mod;
  return a;
}

int sub(int a, int b) {
  a -= b;
  if (a < 0) a += mod;
  return a;
}

int mul(int a, int b) {
  return (int) ((long long) a * b % mod);
}

int power(int a,long long b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) {
      res = mul(res, a);
    }
    a = mul(a, a);
    b >>= 1;
  }
  return res;
}

void ask(int x){
   cout<<"? "<<x<<endl;
 //   fflush(stdout);
   cin>>y;
    for(int i=1;i<=n;i++){
        a[x][i]=power(x,n-i);
    }
    a[x][n+1]=y;
}
int main(){
     ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    n=11;
    for(int i=1;i<=11;i++){
        ask(i);
    }
	for(int i=1;i<=n;i++){
		if(!a[i][i]){
			ma=0;
			for(int j=i+1;j<=n&&!ma;j++)
				if(a[j][i]) ma=j;
			if(!ma) continue;
			for(int j=i;j<=n+1;j++)
				swap(a[ma][j],a[i][j]);
		}
		for(int j=i+1;j<=n;j++){
			tmp=a[j][i];
			if(!tmp) continue;
			for(int k=i;k<=n+1;k++)
                a[j][k]=sub(mul(a[j][k],a[i][i]),mul(a[i][k],tmp));
		}
	}
	for(int i=n;i;i--){
		for(int j=i+1;j<=n;j++)
            a[i][n+1]=sub(a[i][n+1],mul(ans[j],a[i][j]));
			ans[i]=(mul(a[i][n+1],power(a[i][i],mod-2)));
	}
	for(int i=0;i<mod;i++){
        int res=0;
        for(int j=1;j<=11;j++){
            res=add(res,mul(ans[j],power(i,n-j)));
        }
        if(res==0){
        cout<<"! "<<i<<endl;
         //   fflush(stdout);
            return 0;
        }
	}
	cout<<"! -1\n";
	//fflush(stdout);
}