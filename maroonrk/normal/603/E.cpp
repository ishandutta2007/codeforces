#include <bits/stdc++.h>
using namespace std;

using ll=int64_t;
//#define int ll

#define FOR(i,a,b) for(int i=int(a);i<int(b);i++)
#define REP(i,b) FOR(i,0,b)
#define MP make_pair
#define PB push_back
#define ALL(x) x.begin(),x.end()
//#undef MAROON_LOCAL
#ifdef MAROON_LOCAL
#define cerr (cerr<<"-- line "<<__LINE__<<" -- ")
#else
class CerrDummy{}cerrDummy;
template<class T>
CerrDummy& operator<<(CerrDummy&cd,const T&){
	return cd;
}
using charTDummy=char;
using traitsDummy=char_traits<charTDummy>;
CerrDummy& operator<<(CerrDummy&cd,basic_ostream<charTDummy,traitsDummy>&(basic_ostream<charTDummy,traitsDummy>&)){
	return cd;
}
#define cerr cerrDummy
#endif
#define REACH cerr<<"reached"<<endl
#define DMP(x) cerr<<#x<<":"<<x<<endl
#define ZERO(x) memset(x,0,sizeof(x))
#define ONE(x) memset(x,-1,sizeof(x))

using pi=pair<int,int>;
using vi=vector<int>;
using ld=long double;

template<class T,class U>
ostream& operator<<(ostream& os,const pair<T,U>& p){
	os<<"("<<p.first<<","<<p.second<<")";
	return os;
}

template<class T>
ostream& operator <<(ostream& os,const vector<T>& v){
	os<<"[";
	REP(i,(int)v.size()){
		if(i)os<<",";
		os<<v[i];
	}
	os<<"]";
	return os;
}

int read(){
	int i;
	#ifdef int
	scanf("%" SCNd64,&i);
	#else
	scanf("%d",&i);
	#endif
	return i;
}

void printSpace(){
	printf(" ");
}

void printEoln(){
	printf("\n");
}

void print(int x,int suc=1){
	#ifdef int
	printf("%" PRId64,x);
	#else
	printf("%d",x);
	#endif
	if(suc==1)
		printEoln();
	if(suc==2)
		printSpace();
}

void printLL(ll x,int suc=1){
	printf("%" PRId64,x);
	if(suc==1)
		printEoln();
	if(suc==2)
		printSpace();
}

string readString(){
	static char buf[3341000];
	scanf("%s",buf);
	return string(buf);
}

char* readCharArray(){
	static char buf[3341000];
	static int bufUsed=0;
	char* ret=buf+bufUsed;
	scanf("%s",ret);
	bufUsed+=strlen(ret)+1;
	return ret;
}

template<class T,class U>
void chmax(T& a,U b){
	if(a<b)
		a=b;
}

template<class T,class U>
void chmin(T& a,U b){
	if(b<a)
		a=b;
}

template<class T>
T Sq(const T& t){
	return t*t;
}

#define CAPITAL
void Yes(bool ex=true){
	#ifdef CAPITAL
	cout<<"YES"<<endl;
	#else
	cout<<"Yes"<<endl;
	#endif
	if(ex)exit(0);
}
void No(bool ex=true){
	#ifdef CAPITAL
	cout<<"NO"<<endl;
	#else
	cout<<"No"<<endl;
	#endif
	if(ex)exit(0);
}

#ifdef int
const int inf=LLONG_MAX/3;
#else
const int inf=INT_MAX/2-100;
#endif

enum ClusterType{
	NONE,
	BASE,
	RAKE,
	COMPRESS,
	HARDRAKE
};template<class ClusterInfoUtil>
struct TopTree{
	using Info=typename ClusterInfoUtil::Info;
	struct Cluster{
		TopTree* belongingTree;
		ClusterType type;
		Cluster *l,*r,*m,*p;
		Info info,tmpInfo;
		int a,b;
		Cluster(TopTree* tree):info(-1,-1),tmpInfo(-1,-1){
			belongingTree=tree;
			Clear();
		}
		void Clear(){
			type=NONE;
			l=nullptr;
			r=nullptr;
			m=nullptr;
			p=nullptr;
			info=Info(-1,-1);
			tmpInfo=Info(-1,-1);
			a=-1;
			b=-1;
		}
		void UpdateHandles(){
			if(type==BASE){
				belongingTree->handles[a]=this;
				belongingTree->handles[b]=this;
			}else if(type==COMPRESS){
				belongingTree->handles[l->a]=this;
				belongingTree->handles[l->b]=this;
				belongingTree->handles[r->a]=this;
				belongingTree->handles[r->b]=this;
			}
		}
		void Update(){
			if(type==COMPRESS){
				if(m){
					tmpInfo=Info(l->a,l->b);
					tmpInfo.Join(l->a,l->b,m->a,m->b,m->info,l->a,l->b,l->info,RAKE);
				}
				a=l->a;
				b=r->b;
				UpdateHandles();
				info=Info(a,b);
				info.Join(a,b,l->a,l->b,m?tmpInfo:l->info,r->a,r->b,r->info,COMPRESS);
			}else if(type==RAKE){
				a=r->a;
				b=r->b;
				info=Info(a,b);
				info.Join(a,b,l->a,l->b,l->info,r->a,r->b,r->info,RAKE);
			}else if(type==HARDRAKE){
				int la=l->a,lb=l->b;
				int ra=r->a,rb=r->b;
				if(la==ra||la==rb)swap(la,lb);
				if(lb==ra)swap(ra,rb);
				a=ra;
				b=rb;
				info=Info(a,b);
				info.Join(a,b,la,lb,l->info,ra,rb,r->info,RAKE);
			}
		}
		void Reverse(){
			swap(a,b);
		}
		void Normalize(){
			if(type==BASE){
			}else{
				if(type==COMPRESS){
					bool updMid=false;
					if(r->a==a||r->b==a){
						swap(l,r);
						updMid=true;
					}
					if(l->a!=a)l->Reverse();
					if(r->b!=b)r->Reverse();
					if(m&&updMid){
						tmpInfo=Info(l->a,l->b);
						tmpInfo.Join(l->a,l->b,m->a,m->b,m->info,l->a,l->b,l->info,RAKE);
					}
					info.Split(a,b,l->a,l->b,m?tmpInfo:l->info,r->a,r->b,r->info,COMPRESS);
					if(m)tmpInfo.Split(l->a,l->b,m->a,m->b,m->info,l->a,l->b,l->info,RAKE);
				}else if(type==RAKE){
					info.Split(a,b,l->a,l->b,l->info,r->a,r->b,r->info,RAKE);
				}else if(type==HARDRAKE){
					int la=l->a,lb=l->b;
					int ra=r->a,rb=r->b;
					if(la==ra||la==rb)swap(la,lb);
					if(lb==ra)swap(ra,rb);
					info.Split(a,b,la,lb,l->info,ra,rb,r->info,RAKE);
				}
			}
		}
		Cluster* Select(int&xa,int&xb,Info&x,int&ya,int&yb,Info&y){
			Normalize();
			if(type==BASE){
				return this;
			}else{
				if(type==COMPRESS){
					Info lTmp(l->b,l->a),rTmp(r->a,r->b);
					if(xa==xb)lTmp=l->info;
					else lTmp.Join(l->b,l->a,xa,xb,x,l->b,l->a,l->info,RAKE);
					if(ya==yb)rTmp=r->info;
					else rTmp.Join(r->a,r->b,yb,ya,y,r->a,r->b,r->info,RAKE);
					if(m){
						Info mTmp(l->a,l->b);
						mTmp.Join(l->a,l->b,m->a,m->b,m->info,l->a,l->b,lTmp,RAKE);
						bool s=Info::Select(l->a,l->b,mTmp,r->a,r->b,rTmp,COMPRESS);
						if(s){
							xa=l->a,xb=l->b,x=mTmp;
							return r;
						}else{
							mTmp=Info(m->a,m->b);
							mTmp.Join(m->a,m->b,r->b,r->a,rTmp,m->a,m->b,m->info,RAKE);
							s=Info::Select(m->a,m->b,mTmp,l->a,l->b,lTmp,RAKE);
							if(s){
								ya=m->b,yb=m->a,y=mTmp;
								return l;
							}else{
								Info lrTmp(r->b,r->a);
								lrTmp.Join(r->b,r->a,l->a,l->b,lTmp,r->b,r->a,rTmp,RAKE);
								xa=m->a,xb=m->a,x=Info(-1,-1),ya=r->a,yb=r->b,y=lrTmp;
								return m;
							}
						}
					}else{
						bool s=Info::Select(l->a,l->b,lTmp,r->a,r->b,rTmp,COMPRESS);
						if(s){
							xa=l->a,xb=l->b,x=lTmp;
							return r;
						}
						else{
							ya=r->a,yb=r->b,y=rTmp;
							return l;
						}
					}
				}else if(type==RAKE){
					Info w(l->a,l->b);
					if(ya==yb)w=l->info;
					else w.Join(l->a,l->b,yb,ya,y,l->a,l->b,l->info,RAKE);
					bool s=Info::Select(l->a,l->b,w,r->a,r->b,r->info,RAKE);
					if(s){
						xa=r->a,xb=r->a,x=Info(-1,-1),ya=l->b,yb=l->a,y=w;
						return r;
					}else{
						w=Info(r->a,r->b);
						if(ya==yb)w=r->info;
						else w.Join(r->a,r->b,yb,ya,y,r->a,r->b,r->info,RAKE);
						xa=l->a,xb=l->a,x=Info(-1,-1),ya=r->b,yb=r->a,y=w;
						return l;
					}
				}else if(type==HARDRAKE){
					int la=l->a,lb=l->b;
					int ra=r->a,rb=r->b;
					if(la==ra||la==rb)swap(la,lb);
					if(lb==ra)swap(ra,rb);
					Info lTmp(la,lb),rTmp(ra,rb);
					if(ya==yb)lTmp=l->info;
					else lTmp.Join(la,lb,yb,ya,y,la,lb,l->info,RAKE);
					if(xa==xb)rTmp=r->info;
					else rTmp.Join(rb,ra,xa,xb,x,rb,ra,r->info,RAKE);
					bool s=Info::Select(la,lb,lTmp,ra,rb,rTmp,RAKE);
					if(s){
						if(ra==r->a){
							ya=lb,yb=la,y=lTmp;
							return r;
						}else{
							ya=xb,yb=xa,y=x;
							xa=la,xb=lb,x=lTmp;
							return r;
						}
					}else{
						lTmp=Info(ra,rb);
						if(ya==yb)lTmp=rTmp;
						else lTmp.Join(ra,rb,yb,ya,y,ra,rb,rTmp,RAKE);
						if(la==l->a){
							xa=la,xb=la,x=Info(-1,-1),ya=rb,yb=ra,y=lTmp;
							return l;
						}else{
							xa=ra,xb=rb,x=lTmp,ya=la,yb=la,y=Info(-1,-1);
							return l;
						}
					}
				}
			}
			assert(false);
		}
		int Pos(){
			Cluster *x=p;
			if(!x)return 0;
			else if(x->l==this)return -1;
			else if(x->r==this)return 1;
			else if(x->m==this)return -2;
			assert(false);
		}
		bool LinkedToParent(){
			return p&&(p->type!=type||p->m==this);
		}
		void Rotate(){
			Cluster *q=p,*c;
			if(Pos()==1){
				c=l;
				l=q;
				q->r=c; 
			}else{
				c=r;
				r=q;
				q->l=c;
			}
			if(c){
				if(c->p)c->p=q;
			}
			int w=p->Pos();
			p=p->p;
			q->p=this;
			Cluster *x=p;
			if(x){
				if(w==1)x->r=this;
				else if(w==-1)x->l=this;
				else if(w==-2)x->m=this;
			}
			q->Update();
		}
		void Splay(Cluster* guard){
			while(p&&p!=guard&&!LinkedToParent()){
				Cluster *q=p->p;
				if(q&&q!=guard&&!p->LinkedToParent()){
					if(Pos()==p->Pos()){
						p->Rotate();
					}else{
						Rotate();
					}
					Rotate();
				}else{
					Rotate();
				}
			}
			Update();
		}
		void Destroy(){
			info.Destroy(a,b);
		}
	};
	vector<Cluster*> handles;
	vector<Cluster> clusterBuf;
	vi ptrBuf;
	vi deg;
	vector<Cluster*> hardRakeClusters,needUpdateClusters;
	Cluster* selectRoot;
	TopTree(){}
	TopTree(int n){
		Init(n);
	}
	int vertNum,edgeNum;
	void Init(int n){
		int s=n*2+10;
		clusterBuf=vector<Cluster>(s,Cluster(this));
		REP(i,s)ptrBuf.PB(i);
		deg=vi(n,0);
		handles=vector<Cluster*>(n,nullptr);
		vertNum=n;
		edgeNum=0;
		selectRoot=nullptr;
	}
	Cluster* GetNew(){
		Cluster *res=clusterBuf.data()+ptrBuf.back();
		ptrBuf.pop_back();
		res->Clear();
		return res;
	}
	void Recycle(Cluster* ptr){
		ptrBuf.PB(ptr-clusterBuf.data());
	}
	void ClearHardRakeClusters(){
		while(!hardRakeClusters.empty()){
			Cluster* x=hardRakeClusters.back();
			hardRakeClusters.pop_back();
			x->Normalize();
			Recycle(x);
		}
		while(!needUpdateClusters.empty()){
			Cluster* x=needUpdateClusters.back();
			needUpdateClusters.pop_back();
			x->Update();
		}
	}
	void Rectify(Cluster* x,Cluster* guard){
		Cluster* p=x->p;
		if(p!=nullptr){
			Rectify(p,guard);
			if(p==guard&&p->r==x){
				p->Reverse();
				p->Normalize();
			}
		}
		x->Normalize();
	}
	Cluster* CreateCompressCluster(Cluster*l,Cluster*r,Cluster*m){
		auto p=GetNew();
		p->type=COMPRESS;
		p->l=l;
		l->p=p;
		p->r=r;
		r->p=p;
		p->m=m;
		if(m){
			m->p=p;
		}
		p->Update();
		return p;
	}
	Cluster* CreateRakeCluster(Cluster*l,Cluster*r){
		if(!l)return r;
		if(!r)return l;
		auto p=GetNew();
		p->type=RAKE;
		p->l=l;
		l->p=p;
		p->r=r;
		r->p=p;
		p->Update();
		return p;
	}
	Cluster* CreateHardRakeCluster(Cluster*l,Cluster*r){
		if(!l)return r;
		auto p=GetNew();
		hardRakeClusters.PB(p);
		p->type=HARDRAKE;
		p->l=l;
		p->r=r;
		p->Update();
		return p;
	}
	void SoftExpose(int v,Cluster* guard){
		if(handles[v]==guard)return;
		Rectify(handles[v],guard);
		Cluster *x=handles[v],*tmp=x;
		if(x->type==COMPRESS)x->Splay(guard);
		while(x->LinkedToParent()){
			Cluster* p=x->p;
			if(p->type==RAKE){
				p->Splay(nullptr);
				if(x->p!=p)
					x->p->Splay(p);
				x=p;
			}
			x=x->p;
			x->Splay(guard);
		}
		x=tmp;
		while(x->LinkedToParent()){
			Cluster* m=nullptr;
			Cluster* y=x->p;
			if(y->type==RAKE){
				Cluster*p=x->p;
				if(x->Pos()<0){
					m=p->r;
				}else{
					m=p->l;
				}
				y=p->p;
				if(y->type==RAKE){
					Cluster*q=p->p;
					if(p->Pos()<0){
						m=CreateRakeCluster(m,q->r);
					}else{
						m=CreateRakeCluster(m,q->l);
					}
					y=q->p;
					Recycle(q);
				}
				Recycle(p);
			}
			m=CreateRakeCluster(m,y->l);
			y->l->UpdateHandles();
			y->l=x;
			x->p=y;
			y->m=m;
			m->p=y;
			y->Update();
			x=y;
		}
		if(tmp->type==BASE)tmp=tmp->p;
		if(tmp){
			tmp->Splay(guard);
		}
		if(guard)guard->Update();
	}
	bool SoftExpose(int a,int b){
		if(deg[b]==0){
			return false;
		}else if(deg[a]==0){
			SoftExpose(b,nullptr);
			if(handles[b]->a==b){
				handles[b]->Reverse();
				handles[b]->Normalize();
			}
			return false;
		}else if(deg[b]==1){
			SoftExpose(b,nullptr);
			if(handles[b]->a==b){
				handles[b]->Reverse();
				handles[b]->Normalize();
			}
			SoftExpose(a,nullptr);
			if(handles[a]==handles[b]){
				return true;
			}else{
				if(handles[a]->a==a){
					handles[a]->Reverse();
					handles[a]->Normalize();
				}
				return false;
			}
		}else{
			SoftExpose(b,nullptr);
			SoftExpose(a,handles[b]);
			if(handles[a]==handles[b]){
				if(handles[a]->b==a){
					handles[a]->Reverse();
					handles[a]->Normalize();
				}
				return true;
			}else if(handles[a]==handles[b]->l){
				return true;
			}else{
				if(handles[a]->a==a){
					handles[a]->Reverse();
					handles[a]->Normalize();
				}
				return false;
			}
		}
	}
	void SoftExpose(int v){
		if(deg[v]==0){
			//do nothing
		}else{
			SoftExpose(v,nullptr);
			if(handles[v]->a==v){
				handles[v]->Reverse(); 
				handles[v]->Normalize();
			}
		}
	}
	Cluster* HardExpose(int a,int b){
		if(deg[b]==1){
			return handles[a];
		}else if(deg[a]==1){
			needUpdateClusters.PB(handles[b]);
			auto x=handles[b]->l;
			x=CreateHardRakeCluster(handles[b]->m,x);
			x=CreateHardRakeCluster(handles[b]->r,x);
			return x;
		}else{
			needUpdateClusters.PB(handles[b]);
			needUpdateClusters.PB(handles[a]);
			auto x=handles[a]->r;
			x=CreateHardRakeCluster(handles[a]->l,x);
			x=CreateHardRakeCluster(handles[a]->m,x);
			x=CreateHardRakeCluster(handles[b]->m,x);
			x=CreateHardRakeCluster(handles[b]->r,x);
			return x;
		}
	}
	Cluster* HardExpose(int v){
		return HardExpose(handles[v]->a,v);
	}
	Cluster* ExposePath(int a,int b){
		assert(!selectRoot);
		ClearHardRakeClusters();
		if(deg[a]>deg[b])swap(a,b);
		bool connected=SoftExpose(a,b);
		if(!connected)return nullptr;
		return HardExpose(a,b);
	}
	Info* Expose(int a,int b){
		//cerr<<"expose "<<a<<" "<<b<<endl;
		if(a==b)return Expose(a);
		Cluster*x=ExposePath(a,b);
		if(x)return &(x->info);
		else return nullptr;
	}
	Cluster* ExposeVertex(int v){
		assert(!selectRoot);
		ClearHardRakeClusters();
		SoftExpose(v);
		if(deg[v]==0)return nullptr;
		return HardExpose(v);
	}
	Info* Expose(int v){
		//cerr<<"expose "<<v<<endl;
		Cluster*x=ExposeVertex(v);
		if(x)return &(x->info);
		else return nullptr;
	}
	bool Connected(int a,int b){
		//cerr<<"connected "<<a<<" "<<b<<endl;
		assert(!selectRoot);
		ClearHardRakeClusters();
		if(deg[a]>deg[b])swap(a,b);
		return SoftExpose(a,b);
	}
	template <class... Args>
	bool Link(int a,int b,Args... args){
		assert(!selectRoot);
		ClearHardRakeClusters();
		if(deg[a]>deg[b])swap(a,b);
		//cerr<<"link "<<a<<" "<<b<<endl;
		bool connected=SoftExpose(a,b);
		if(connected)return false;
		Cluster* u=handles[a],*v=handles[b];
		Cluster* x=GetNew();
		x->type=BASE;
		x->a=a;
		x->b=b;
		x->info=Info(a,b);
		x->info.Create(a,b,args...);
		x->UpdateHandles();
		Cluster* y=nullptr;
		if(deg[a]==0){
			y=x;
		}else if(deg[a]==1){
			y=CreateCompressCluster(u,x,nullptr);
		}else{
			u->r->Reverse();
			u->r->UpdateHandles();
			y=CreateCompressCluster(u->l,x,CreateRakeCluster(u->r,u->m));
			Recycle(u);
		}
		if(deg[b]==0){
		}else if(deg[b]==1){
			v->Reverse();
			v->Normalize();
			CreateCompressCluster(y,v,nullptr);
		}else{
			v->l->UpdateHandles();
			CreateCompressCluster(y,v->r,CreateRakeCluster(v->m,v->l));
			Recycle(v);
		}
		deg[a]++;
		deg[b]++;
		edgeNum++;
		return true;
	}
	pair<Cluster*,Cluster*> SplitMiddleChild(Cluster*x){
		if(x->type!=RAKE)return MP(x,nullptr);
		while(x->type==RAKE)x=x->l;
		x->p->Splay(nullptr);
		Cluster* tmp=x->p;
		pair<Cluster*,Cluster*>  res=MP(tmp->l,tmp->r);
		Recycle(tmp);
		return res;
	}
	bool Cut(int a,int b){
		assert(!selectRoot);
		ClearHardRakeClusters();
		if(deg[a]>deg[b])swap(a,b);
		//cerr<<"cut "<<a<<" "<<b<<endl;
		bool connected=SoftExpose(a,b);
		if(!connected)return false;
		Cluster *u=handles[a],*v=handles[b];
		if(deg[b]==1){
			if(u->type!=BASE)return false;
			u->Destroy();
			Recycle(u);
			handles[a]=nullptr;
			handles[b]=nullptr;
		}else if(deg[a]==1){
			if(v->l->type!=BASE)return false;
			if(deg[b]==2){
				v->r->p=nullptr;
				v->r->UpdateHandles();
			}else{
				pair<Cluster*,Cluster*> z=SplitMiddleChild(v->m);
				CreateCompressCluster(z.first,v->r,z.second);
			}
			v->l->Destroy();
			Recycle(v->l);
			Recycle(v);
			handles[a]=nullptr;
		}else{
			if(u->r->type!=BASE)return false;
			if(deg[a]==2){
				u->l->p=nullptr;
				u->l->UpdateHandles();
			}else{
				pair<Cluster*,Cluster*> z=SplitMiddleChild(u->m);
				z.first->Reverse();
				CreateCompressCluster(u->l,z.first,z.second);
			}
			if(deg[b]==2){
				v->r->p=nullptr;
				v->r->UpdateHandles();
			}else{
				pair<Cluster*,Cluster*> z=SplitMiddleChild(v->m);
				CreateCompressCluster(z.first,v->r,z.second);
			}
			u->r->Destroy();
			Recycle(u->r);
			Recycle(u);
			Recycle(v);
		}
		deg[a]--;
		deg[b]--;
		edgeNum--;
		return true;
	}
	Info* PrepareForSelect(int a,int b){
		//cerr<<"prepare "<<a<<" "<<b<<endl;
		if(a==b)return PrepareForSelect(a);
		selectRoot=ExposePath(a,b);
		if(selectRoot==nullptr)return nullptr;
		return &(selectRoot->info);
	}
	Info* PrepareForSelect(int v){
		//cerr<<"prepare "<<v<<endl;
		selectRoot=ExposeVertex(v);
		if(selectRoot==nullptr)return nullptr;
		return &(selectRoot->info);
	}
	struct SelectedEdge{
		Info* info;
		int a,b;
	};
	SelectedEdge Select(){
		assert(selectRoot);
		assert(!selectRoot->p);
		Cluster* cur=selectRoot;
		int xa=cur->a,xb=xa,ya=cur->b,yb=ya;
		Info x(-1,-1),y(-1,-1);
		while(1){
			Cluster*nx=cur->Select(xa,xb,x,ya,yb,y);
			if(nx==cur)break;
			cur=nx;
		}
		int a=cur->a,b=cur->b;
		selectRoot=nullptr;
		return SelectedEdge{Expose(a,b),a,b};
	}
	int NumofVertices(){
		return vertNum;
	}
	int NumofEdges(){
		return edgeNum;
	}
};

struct InfoBase{
	private:
	int vert[2];
	void SetVertex(int a,int b){
		vert[0]=a;
		vert[1]=b;
	}
	public:
	InfoBase(int a,int b){
		SetVertex(a,b);
	}
	inline int idx(int v){
		if(vert[0]==v)return 0;
		if(vert[1]==v)return 1;
		assert(false);
	}
	inline int another(int v){
		if(vert[0]==v)return vert[1];
		if(vert[1]==v)return vert[0];
		assert(false);
	}
	inline int v0(){
		return vert[0];
	}
	inline int v1(){
		return vert[1];
	}
};

struct Info:InfoBase{
	int s,mx;
	Info(int a,int b):InfoBase(a,b){}
	void Join(int a,int b,int la,int lb,Info&l,int ra,int rb,Info&r,ClusterType type){
		//(another(a)==b);
		//(another(b)==a);
		if(type==RAKE){
			//(a==ra);
			//(b==rb);
			//(lb==rb);
			
			mx=r.mx;
		}else if(type==COMPRESS){
			//(a==la);
			//(lb==ra);
			//(rb==b);
			
			mx=max(l.mx,r.mx);
		}
			
		s=l.s+r.s-1;
	}
	void Create(int a,int b,int c){
		//(another(a)==b);
		//(another(b)==a);
		
		s=2;
		mx=c;
	}
	void Split(int a,int b,int la,int lb,Info&l,int ra,int rb,Info&r,ClusterType type){
		//(another(a)==b);
		//(another(b)==a);
		if(type==RAKE){
			//(a==ra);
			//(b==rb);
			//(lb==rb);
		}else if(type==COMPRESS){
			//(a==la);
			//(lb==ra);
			//(rb==b);
		}
	}
	void Destroy(int a,int b){
		//(another(a)==b);
		//(another(b)==a);
	}
	static bool Select(int la,int lb,Info l,int ra,int rb,Info r,ClusterType type){
		if(type==RAKE){
			//(lb==rb);
			return true;
		}else if(type==COMPRESS){
			//(lb==ra);
			return l.mx<=r.mx;
		}
		assert(false);
	}
};

int Size(Info*x){
	return x?x->s:1;
}

struct Edge{
	int a,b,c;
	bool operator<(const Edge&e)const{
		if(c!=e.c)return c<e.c;
		else if(a!=e.a) return a<e.a;
		else return b<e.b;
	}
};

signed main(){
	int n=read(),m=read();
	TopTree<Info> tree(n);
	int odds=n;
	set<Edge> es;
	const auto Link=[&](int a,int b,int c){
		int p=Size(tree.Expose(a));
		int q=Size(tree.Expose(b));
		bool res=tree.Link(a,b,c);
		assert(res);
		if(p%2)odds--;
		if(q%2)odds--;
		if((p+q)%2)odds++;
		es.insert(Edge{a,b,c});
	};
	const auto Cut=[&](int a,int b,int c){
		bool res=tree.Cut(a,b);
		assert(res);
		int p=Size(tree.Expose(a));
		int q=Size(tree.Expose(b));
		if(p%2)odds++;
		if(q%2)odds++;
		if((p+q)%2)odds--;
		es.erase(Edge{a,b,c});
	};
	REP(_,m){
		int a=read()-1,b=read()-1,c=read();
		if(a>b)swap(a,b);
		if(tree.PrepareForSelect(a,b)){
		cerr<<odds<<endl;
			auto e=tree.Select();
		cerr<<odds<<endl;
			if(e.a>e.b)swap(e.a,e.b);
		cerr<<odds<<endl;
			if(c<e.info->mx){
		cerr<<odds<<endl;
				Cut(e.a,e.b,e.info->mx);
		cerr<<odds<<endl;
				Link(a,b,c);
		cerr<<odds<<endl;
			}else{
				//do nothing
			}
		}else{
			cerr<<a<<" "<<b<<endl;
		cerr<<odds<<endl;
			Link(a,b,c);
		cerr<<odds<<endl;
		}
		cerr<<odds<<endl;
		if(odds==0){
			REACH;
			while(1){
		cerr<<odds<<endl;
				assert(!es.empty());
				auto itr=es.end();itr--;
				Edge e=*itr;
				Cut(e.a,e.b,e.c);
		cerr<<odds<<endl;
				if(odds>0){
					Link(e.a,e.b,e.c);
		cerr<<odds<<endl;
					break;
				}
		cerr<<odds<<endl;
			}
			REACH;
			auto itr=es.end();itr--;
			REACH;
			print(itr->c);
		}else{
			print(-1);
		}
	}
}