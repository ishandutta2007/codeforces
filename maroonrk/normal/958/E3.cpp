#include <bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(int)(N);i++)
#define rep1(i,N) for(int i=1;i<=(int)(N);i++)
#define show(x) cout<< #x<< " "<<(x)<<endl;
#define all(c) c.begin(),c.end()
#define chmax(x,y) x = max(x,y)
#define fs first
#define sc second
#define pb push_back

using namespace std;

int N;
struct Point{
	int x,y;
	int i;
	bool c;
	Point(int x,int y,int i,bool c):x(x),y(y),i(i),c(c){}
	friend ostream& operator<<(ostream &o,const Point& x){
		return o<<"("<<x.x<<","<<x.y<<") col = "<<x.c<<" id = "<<x.i;
	}

};

vector<int> ans;

inline int sho(int x,int y){
	if(x>0 && y>=0) return 0;
	if(x<=0 && y>0) return 1;
	if(x<0 && y<=0) return 2;
	if(x>=0 && y<0) return 3;
	return 4;
}
bool comp(Point p,Point q){
	int s = sho(p.x,p.y);
	int t = sho(q.x,q.y);
	if(s!=t) return s<t;
	return p.y*q.x<p.x*q.y;
}

void solve(vector<Point> ps){
//	printf("--------------- solve ps = ");
//	for(Point p:ps) cout<<" - "<<p<<endl;;
//	puts("");
	int n = ps.size()/2;
	if(n==0){
		return;
	}
	int oid = -1;
	while(true){
		oid = rand()%(2*n);
		if(ps[oid].c) break;
	}
	//oid: c = 1
	rep(i,n*2) if(i!=oid){
		ps[i].x -= ps[oid].x;
		ps[i].y -= ps[oid].y;
	}
	ps[oid].x = ps[oid].y = 0;

	sort(all(ps),comp);
	Point o = ps.back();
	ps.pop_back();

	vector<int> sm(4*n);
	int V = 2*n-1;
	rep(i,2*V){
		sm[i+1] = sm[i] + (ps[i%V].c ? 1 : -1);
	}

//	show(V);
	rep(i,V) if(!ps[i].c){
		int j = lower_bound(all(ps),Point(-ps[i].x,-ps[i].y,0,0),comp) - ps.begin();
		assert(j!=2*n);
		if(j == 2*n-1) j = 0;
//		show(i);
//		show(j);
		if(i>=j) j+=V;
		if(sm[j]-sm[i] == -1){
			//ok!
			Point p = ps[i];
			ans[p.i] = o.i;
//			printf("ans[%d] = %d\n",p.i+1,o.i+1);

			vector<Point> ps1,ps2;
			for(int x = (i+1)%V;x!=j%V;x=(x+1)%V){
				ps1.pb(ps[x]);
			}
			for(int x = j%V;x!=i;x=(x+1)%V){
				ps2.pb(ps[x]);
			}
			solve(ps1);
			solve(ps2);
			return;
		}
	}
//	assert(0);
	ps.pb(o);
	solve(ps);
}

int main(){
	srand((unsigned)time(NULL));
	cin>>N;
	ans.resize(N);
	vector<Point> ps;
	rep(t,2){
		rep(i,N){
			int x,y;
			cin>>x>>y;
			ps.pb(Point(x,y,i,t));
		}
	}
	solve(ps);
	rep(i,N) cout<<ans[i]+1<<endl;
}