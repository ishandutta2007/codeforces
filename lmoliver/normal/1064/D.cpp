#include<bits/stdc++.h>
using namespace std;
/* loops */
#define F(p) for(int (p)=0;p<n;p++)
#define Fm(p) for(int (p)=0;p<m;p++)
#define Fd(p) for(int (p)=n-1;p>=0;p--)
#define Fdm(p) for(int (p)=m-1;p>=0;p--)
#define FI(p) for(int (p)=1;p<=n;p++)
#define FIm(p) for(int (p)=1;p<=m;p++)
#define FId(p) for(int (p)=n;p>=1;p--)
#define FIdm(p) for(int (p)=m;p>=1;p--)
/* LL & INF */
typedef long long LL;
const int INF=(1<<30)-(1<<6);
const LL LINF=((LL)1<<62)-(1<<6);
/* read template */
template<int L,int R,class T=int>struct Parray{T arr[R-L+1];inline int& operator[] (int i){return arr[i-L];}};void inline _read(int &x){scanf("%d",&x);}void inline _read(LL &x){scanf("%I64d",&x);}void inline _read(char *x){scanf("%s",x);}void inline _read(string &x){cin>>x;}void inline readln(string &x){getline(cin,x);}void inline _read(const char *x){scanf(x);}template<typename T1>inline void read(T1 &x1){_read(x1);}template<typename T1,typename T2>inline void read(T1 &x1,T2 &x2){_read(x1);read(x2);}template<typename T1,typename T2,typename T3>inline void read(T1 &x1,T2 &x2,T3 &x3){_read(x1);read(x2,x3);}template<typename T1,typename T2,typename T3,typename T4>inline void read(T1 &x1,T2 &x2,T3 &x3,T4 &x4){_read(x1);read(x2,x3,x4);}

int n,m,r,c,x,y;
struct Node{
	int x;
	int y;
	int p;
	inline int dis()const{
		return abs(y-c)+2*p;
	}
};

bool operator <(const Node a,const Node b){
//	return a.dis()>b.dis();
return a.p>b.p;
}

priority_queue<Node> q;

char mp[2020][2020]={'\0'};

int main(){
	read(n,m);
	read(r,c);
	read(x,y);
//	FI(i)mp[i][0]=mp[i][m+1]='*';
//	FIm(i)mp[0][i]=mp[n+1][i]='*';
	FI(i)FIm(j){
		do{
			scanf("%c",&mp[i][j]);
		}while(mp[i][j]!='.'&&mp[i][j]!='*');
	}
	q.push((Node){r,c,0});
	int ans=0;
	while(!q.empty()){
		Node now=q.top();
		q.pop();
		int nr=now.x,nc=now.y,np=now.p;
		if(max(nc-c,0)+np>y||max(c-nc,0)+np>x)continue;
		if(mp[nr][nc]!='.')continue;
		mp[nr][nc]='!';
		ans++;
//		cout<<nr<<","<<nc<<endl;
		q.push((Node){nr+1,nc,np});
		q.push((Node){nr-1,nc,np});
		int dir=nc==c?0:(nc>c?1:-1);
		q.push((Node){nr,nc+1,np+(dir==-1?1:0)});
		q.push((Node){nr,nc-1,np+(dir==1?1:0)});
	}
//	FI(i){
//		FIm(j){
//			cout<<mp[i][j];	
//		}
//		cout<<endl;
//	}
	cout<<ans<<endl;
    return 0;
}