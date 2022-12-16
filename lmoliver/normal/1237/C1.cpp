#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define F(N,S,E) for(int N=(int)(S);N<=(int)(E);N++)

struct P{
	int x,y,z,id;
	P(){}
	P(int x,int y,int z,int id):x(x),y(y),z(z),id(id){}
	int dis(const P &o)const{
		return abs(x-o.x)+abs(y-o.y)+abs(z-o.z);
	}
};

struct CmpX{
	bool operator()(const P &a,const P &b){
		return a.x<b.x;
	}
};

struct CmpY{
	bool operator()(const P &a,const P &b){
		return a.y<b.y;
	}
};

struct CmpZ{
	bool operator()(const P &a,const P &b){
		return a.z<b.z;
	}
};

struct CmpD{
	P p;
	CmpD(P p):p(p){}
	bool operator()(const P &a,const P &b){
		return p.dis(a)<p.dis(b);
	}
};

const int N=1001001;
P x[N];

int main(){
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	F(i,1,n){
		int a,b,c;
		cin>>a>>b>>c;
		x[i]=P(a,b,c,i);
	}
	x[0]=P(0,0,0,-1);
	x[n+1]=P(INT_MAX,INT_MAX,INT_MAX,-1);
	sort(x+1,x+n+1,CmpX());
	int f=1;
	F(i,1,n){
		if(x[i].x!=x[i+1].x){
			//[f,i]
			if(f%2==0){
				sort(x+f,x+i+1,CmpD(x[f-1]));
				f++;
			}
			sort(x+f,x+i+1,CmpY());
			int g=f;
			F(j,f,i){
				if(j==i||x[j].y!=x[j+1].y){
					//[g,j]
					if(g%2==0){
						sort(x+g,x+j+1,CmpD(x[g-1]));
						g++;
					}
					sort(x+g,x+j+1,CmpZ());
					g=j+1;
				}
			}
			f=i+1;
		}
	}
	F(i,1,n){
		cout<<x[i].id<<" "<<x[i+1].id<<endl;
		i++;
	}
	return 0;
}