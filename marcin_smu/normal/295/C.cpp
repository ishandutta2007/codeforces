#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
#include<stack>
using namespace std;
typedef pair<int,int> PI;
typedef long long LL;
typedef double D;
#define FI first
#define SE second
#define MP make_pair
#define PB push_back
#define R(I,N) for(int I=0;I<N;I++)
#define F(I,A,B) for(int I=A;I<B;I++)
#define FD(I,N) for(int I=N-1;I>=0;I--)
#define make(A) scanf("%d",&A);
#define makel(A) scanf("%I64d",&A);
#define pll(A) printf("%I64d ",A);
const int P=1000*1000*1000+7;
int n,k,a,b,odl[51][51][2],wyn[51][51][2];
struct cos{
  int a,b,s; 
  int odll(){
		return odl[a][b][s];
	}
	int wynn(){
		return wyn[a][b][s];
	}
}pom;
queue<cos> kol;
void dod(int aa,int bb,int s,int od,int l){
	if(odl[aa][bb][s]>od){
		odl[aa][bb][s]=od;
		pom.a=aa;
		pom.b=bb;
		pom.s=s;
		kol.push(pom);
	}
  if(odl[aa][bb][s]==od){
	  wyn[aa][bb][s]+=l;
	  if(wyn[aa][bb][s]>P)
	  wyn[aa][bb][s]-=P;
	}
}
LL od(LL a){
 int x=P-2;
 LL wyn=1;
 while(x){
  if(x&1){
   wyn*=a;
   wyn%=P;
  }
  a*=a;
  a%=P;
  x/=2;
 }
 return wyn;
}
LL sil[51],odw[51];
LL po(int a,int b){
 if(b>a)return 0;
 return sil[a]*odw[b]%P*odw[a-b]%P;
}
main(){
	sil[0]=1;
	odw[0]=1;
	for(int i=1;i<51;i++){
		sil[i]=sil[i-1]*i%P;
		odw[i]=od(sil[i]);
	}
	make(n);
	make(k);k/=50;
	R(i,n){
	  int pom;
	  make(pom);
	  if(pom==50)a++;else b++;
	}
	R(i,a+1)R(j,b+1)R(l,2){
	  odl[i][j][l]=n*n+1;
	}
	dod(a,b,0,0,1);
	while(kol.empty()==0){
	  cos ak=kol.front();kol.pop();
	  if(ak.s==0){
			R(i,ak.a+1)R(j,ak.b+1){
				if(i+2*j<=k&&i+j>0){
					int pom = po(ak.a,i)*po(ak.b,j)%P*ak.wynn()%P;
					dod(ak.a-i,ak.b-j,!ak.s,ak.odll()+1,pom);
				}
			}
		}else{
			R(i,a-ak.a+1)R(j,b-ak.b+1){
				if(i+2*j<=k&&i+j>0){
					int pom = po(a-ak.a,i)*po(b-ak.b,j)%P*ak.wynn()%P;
					dod(ak.a+i,ak.b+j,!ak.s,ak.odll()+1,pom);
				}
			}
		}
	}
	if(odl[0][0][1]==n*n+1)
		printf("-1\n0\n");
	else
		printf("%d\n%d\n",odl[0][0][1],wyn[0][0][1]);
}