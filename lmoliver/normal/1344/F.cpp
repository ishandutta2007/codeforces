#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=2048;
typedef bitset<N> B;
int v[N];
int ss[N];
int vv(char c){
	return c=='W'?0:c=='R'?1:c=='Y'?2:3;
}
B a[N];
bool ha[N]={false};
void gg(){
	puts("NO");
	exit(0);
}
int n,k;
void ins(B &b){
	for(int i=2*n;i>=0;i--){
		if(b[i]){
			if(ha[i]){
				b^=a[i];
			}
			else{
				ha[i]=true;
				a[i]=b;
				if(i==0){
					gg();
				}
				return;
			}
		}
	}
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		ss[2*i]=1; // 0:low
		ss[2*i+1]=2; // 1:high
	}
	while(k--){
		char op[10];
		scanf("%s",op);
		int cnt;
		scanf("%d",&cnt);
		for(int i=0;i<cnt;i++){
			scanf("%d",&v[i]);
		}
		// W:0 R:1 Y:2 B:3
		if(op[0]=='m'){ // mix
			scanf("%s",op);
			int vl=vv(op[0]);
			B b[2];
			for(int i=0;i<cnt;i++){
				int x=v[i];
				for(int j=0;j<2;j++){
					for(int k=0;k<2;k++){
						b[j][2*x-1+k]=(ss[2*x+j]>>k)&1;
					}
				}
			}
			for(int i=0;i<2;i++){
				b[i][0]=(vl>>i)&1;
				ins(b[i]);
			}
		}
		else if(op[0]=='Y'){ // YB
			for(int i=0;i<cnt;i++){
				int x=v[i];
				ss[2*x]^=ss[2*x+1];
			}
		}
		else if(op[1]=='Y'){ // RY
			for(int i=0;i<cnt;i++){
				int x=v[i];
				swap(ss[2*x],ss[2*x+1]);
			}
		}
		else{ // RB
			for(int i=0;i<cnt;i++){
				int x=v[i];
				ss[2*x+1]^=ss[2*x];
			}
		}
	}
	puts("YES");
	B ans;
	ans[0]=true;
	for(int i=1;i<=2*n;i++){
		if(ha[i]){
			ans[i]=(a[i]&ans).count()&1;
		}
		else{
			ans[i]=0;
		}
	}
	for(int i=1;i<=n;i++){
		putchar(".RYB"[ans[2*i-1]+ans[2*i]*2]);
	}
	printf("\n");
	return 0;
}