#include <bits/stdc++.h>
                                        #include<iostream>
                                        #include<cstdio>
                                        #include<vector>
                                        #include<queue>
                                        #include<map>
                                        #include<cstring>
                                        #include<string>
                                        #include <math.h>
                                        #include<algorithm>
                                    //    #include <boost/multiprecision/cpp_int.hpp>
                                        #include<functional>
                               #define int long long
                                        #define inf  1000000007
                                        #define pa pair<int,int>
                                        #define ll long long
                                        #define pal pair<double,double>
                                        #define ppap pair<pa,int>
                                  
                                        #define ssa pair<string,int>
                                        #define  mp make_pair
                                        #define  pb push_back
                                        #define EPS (1e-8)
                                        #define equals(a,b) (fabs((a)-(b))<EPS)
int dx[4]={0,-1,0,1};
int dy[4]={1,0,-1,0};
                                        using namespace std;
                               			class pa3{
                                        	public:
                                        	int x,y,z;
                                        	pa3(int x=0,int y=0,int z=0):x(x),y(y),z(z) {}
                                        	bool operator < (const pa3 &p) const{
                                        		if(x!=p.x) return x<p.x;
                                        		if(y!=p.y) return y<p.y;
                                        		 return z<p.z;
                                        		//return x != p.x ? x<p.x: y<p.y;
                                        	}
                               				bool operator > (const pa3 &p) const{
                                        		if(x!=p.x) return x>p.x;
                                        		if(y!=p.y) return y>p.y;
                                        		 return z>p.z;
                                        		//return x != p.x ? x<p.x: y<p.y;
                                        	}
                                        	bool operator == (const pa3 &p) const{
                                        		return x==p.x && y==p.y && z==p.z;
                                        	}
                                        		bool operator != (const pa3 &p) const{
                                        			return !( x==p.x && y==p.y && z==p.z);
                                        	}
                                        
                                        };
                                        
                                        class pa4{
                                        	public:
                                        	double x;
                                        	int y,z,w;
                                        	pa4(double x=0,int y=0,int z=0,int w=0):x(x),y(y),z(z),w(w) {}
                                        	bool operator < (const pa4 &p) const{
                                        		if(x!=p.x) return x<p.x;
                                        		if(y!=p.y) return y<p.y;
                                        		if(z!=p.z)return z<p.z;
                                        		return w<p.w;
                                        		//return x != p.x ? x<p.x: y<p.y;
                                        	}
                                        	bool operator > (const pa4 &p) const{
                                        		if(x!=p.x) return x>p.x;
                                        		if(y!=p.y) return y>p.y;
                                        		if(z!=p.z)return z>p.z;
                                        		return w>p.w;
                                        		//return x != p.x ? x<p.x: y<p.y;
                                        	}
                                        	bool operator == (const pa4 &p) const{
                                        		return x==p.x && y==p.y && z==p.z &&w==p.w;
                                        	}
                                        		
                                        
                                        };
                                        class pa2{
                                        	public:
                                        	int x,y;
                                        	pa2(int x=0,int y=0):x(x),y(y) {}
                                        	pa2 operator + (pa2 p) {return pa2(x+p.x,y+p.y);}
                                        	pa2 operator - (pa2 p) {return pa2(x-p.x,y-p.y);}
                                        	pa2 operator * (int a) {return pa2(x*a,y*a);}
                                        	bool operator < (const pa2 &p) const{
                                        		return x != p.x ? x<p.x: y<p.y;
                                        	}
                                        	bool operator > (const pa2 &p) const{
                                        		return x != p.x ? x>p.x: y>p.y;
                                        	}
                                        	bool operator == (const pa2 &p) const{
                                        		return abs(x-p.x)==0 && abs(y-p.y)==0;
                                        	}
                                        	bool operator != (const pa2 &p) const{
                                        		return !(abs(x-p.x)==0 && abs(y-p.y)==0);
                                        	}
                                        		
                                        
                                        };
                                        
                                               #define ppa pair<int,pas>
                                        class Point{
                                        	public:
                                        	double x,y;
                                        	Point(double x=0,double y=0):x(x),y(y) {}
                                        	Point operator + (Point p) {return Point(x+p.x,y+p.y);}
                                        	Point operator - (Point p) {return Point(x-p.x,y-p.y);}
                                        	Point operator * (double a) {return Point(x*a,y*a);}
                                        	Point operator / (double a) {return Point(x/a,y/a);}
                                        	double absv() {return sqrt(norm());}
                                        	double norm() {return x*x+y*y;}
                                        	bool operator < (const Point &p) const{
                                        		return x != p.x ? x<p.x: y<p.y;
                                        	}
                                        	bool operator == (const Point &p) const{
                                        		return fabs(x-p.x)<EPS && fabs(y-p.y)<EPS;
                                        	}
                                        };
                                        typedef Point Vector;
                                 #define pl pair<int,pas>
                                        struct Segment{
                                        Point p1,p2;
                                        };
                                         double dot(Vector a,Vector b){
                                        	return a.x*b.x+a.y*b.y;
                                        }
                                        double cross(Vector a,Vector b){
                                        	return a.x*b.y-a.y*b.x;
                                        }
                                    
            bool parareru(Point a,Point b,Point c,Point d){
            //	if(abs(cross(a-b,d-c))<EPS)cout<<"dd "<<cross(a-b,d-c)<<endl;
            	return abs(cross(a-b,d-c))<EPS;
            }
            double distance_ls_p(Point a, Point b, Point c) {
              if ( dot(b-a, c-a) < EPS ) return (c-a).absv();
              if ( dot(a-b, c-b) < EPS ) return (c-b).absv();
              return abs(cross(b-a, c-a)) / (b-a).absv();
            }
            bool is_intersected_ls(Segment a,Segment b) {
            	if(a.p1==b.p1||a.p2==b.p1||a.p1==b.p2||a.p2==b.p2) return true;
            	/*
            	if(parareru((a.p2),(a.p1),(b.p1),(b.p2))&&parareru((a.p2),(a.p1),(b.p2),(b.p1))){
            //		cout<<"sss"<<endl;
            		if(dot(a.p1-b.p1,a.p1-b.p2)<EPS) return true;
            		if(dot(a.p2-b.p1,a.p2-b.p2)<EPS) return true;
            		if(dot(a.p1-b.p1,a.p2-b.p1)<EPS) return true;
            		if(dot(a.p1-b.p2,a.p2-b.p2)<EPS) return true;
            		return false;
            	}
            	*/
               return ( cross(a.p2-a.p1, b.p1-a.p1) * cross(a.p2-a.p1, b.p2-a.p1) < EPS ) && ( cross(b.p2-b.p1, a.p1-b.p1) * cross(b.p2-b.p1, a.p2-b.p1) < EPS );
            }
             
            double segment_dis(Segment a,Segment b){
            	if(is_intersected_ls(a,b))return 0;
            	double r=distance_ls_p(a.p1, a.p2, b.p1);
            	r=min(r,distance_ls_p(a.p1, a.p2, b.p2));
            	r=min(r,distance_ls_p(b.p1, b.p2, a.p2));
            	r=min(r,distance_ls_p(b.p1, b.p2, a.p1));
            	return r;
            }
            Point intersection_ls(Segment a, Segment b) {
              Point ba = b.p2-b.p1;
              double d1 = abs(cross(ba, a.p1-b.p1));
              double d2 = abs(cross(ba, a.p2-b.p1));
              double t = d1 / (d1 + d2);
             
              return a.p1 + (a.p2-a.p1) * t;
            }
             
                            string itos( int i ) {
                            ostringstream s ;
                            s << i ;
                            return s.str() ;
                            }
                             
                            int gcd(int v,int b){
                            	if(v>b) return gcd(b,v);
                            	if(v==b) return b;
                            	if(b%v==0) return v;
                            	return gcd(v,b%v);
                            }
             
                            double distans(double x1,double y1,double x2,double y2){
                            	double rr=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
                            	return sqrt(rr);
                            	
                            }
             /*               
            int pr[1000010];
            int inv[1000010];
            
            int beki(int wa,int rr,int warukazu){
            	if(rr==0) return 1%warukazu;
            	if(rr==1) return wa%warukazu;
            	if(rr%2==1) return (beki(wa,rr-1,warukazu)*wa)%warukazu;
            	int zx=beki(wa,rr/2,warukazu);
            	return (zx*zx)%warukazu;
            }
double bekid(double w,int r){
	if(r==0) return 1.0;
	if(r==1) return w;
	if(r%2) return bekid(w,r-1)*w;
	double f=bekid(w,r/2);
	return f*f;
}

            
			int comb(int nn,int rr){
				int r=pr[nn]*inv[rr];
				r%=inf;
				r*=inv[nn-rr];
				r%=inf;
				return r;
			}
            
            
            void gya(int ert){
            	pr[0]=1;
            	for(int i=1;i<=ert;i++){
            		pr[i]=(pr[i-1]*i)%inf;
            	}
           	for(int i=0;i<=ert;i++) inv[i]=beki(pr[i],inf-2,inf);
            	
            }
            */ 
			//priority_queue<pa3,vector<pa3>,greater<pa3>> pq;            
             //sort(ve.begin(),ve.end(),greater<int>());
                                     //----------------kokomade tenpure------------
            //vector<double> ans(100000000),ans2(100000000)
queue<pa> qu;
priority_queue<pa> pq;  
vector<int> G[100020];
vector<int> G2[100020];
int oya[100020];
bool onc[100020]={0};
int ans[100020];
void dfs2(int r,int oya2){
	oya[r]=oya2;
	for(auto v:G[r])if(v!=oya2){
		G2[r].pb(v);
		dfs2(v,r);
	}
}
int jisu[100020]={0};
vector<int> cho;
int n;
int dep[100020]={0};
int yurai[100020]={0};

pa dfs(int r){
	if(dep[r]>0) return mp(dep[r],yurai[r]);
	if(G2[r].size()==0){
		dep[r]=1;
		yurai[r]=r;
		return mp(1,r);
	}
	pa z=mp(-1,1);
	for(auto v:G2[r]){
		z=max(z,dfs(v));
	}
	dep[r]=z.first+1;
	yurai[r]=z.second;
	return mp(dep[r],yurai[r]);
}

void shutu(){

	for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
	cout<<endl;
	exit(0);
}
signed main(){

	cin>>n;
	for(int i=1;i<=n;i++)ans[i]=n;
	ans[1]=1;
	
	for(int i=0;i<n-1;i++){
	int y,yy;
		cin>>y>>yy;
		jisu[y]++;
		jisu[yy]++;
		
		G[y].pb(yy);
		G[yy].pb(y);
	}

	qu.push(mp(1,-1));
	int haji=0;
	while(qu.size()){
		pa z=qu.front();
		qu.pop();
		haji=z.first;
		for(auto v:G[z.first])if(v!=z.second) qu.push(mp(v,z.first));
	
	}
	
	int haji2;
	qu.push(mp(haji,-1));
	while(qu.size()){
		pa z=qu.front();
		qu.pop();
		haji2=z.first;
		for(auto v:G[z.first])if(v!=z.second) qu.push(mp(v,z.first));
	
	}
//	cout<<haji<<" "<<haji2<<endl;
	dfs2(haji,-1);
	int r=haji2;
	while(1){
		cho.pb(r);
		onc[r]=1;
		r=oya[r];
		if(r<0) break;
	}
	//cout<<cho.size()<<endl;
	if(cho.size()==n){
		shutu();
	}
	ans[2]=cho.size();
	
	for(int i=1;i<=n;i++)if(onc[i]==0) dfs(i);
	
	
	for(auto v:cho)for(auto vv:G2[v])if(onc[vv]==0){
		pq.push(dfs(vv));
	}
	
	int it=3;
	while(pq.size()){
		pa z=pq.top();
		pq.pop();
		
		ans[it]=ans[it-1]+z.first;
		it++;
		int f=z.second;
		while(1){
			if(onc[f]) break;
			onc[f]=1;
			for(auto v:G2[f])if(onc[v]==0){
				pq.push(dfs(v));
			}
			f=oya[f];
		}
		
	}
	shutu();
	
	return 0;
        }