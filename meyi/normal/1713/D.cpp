#include<bits/stdc++.h>
using namespace std;
#define ri int
typedef long long ll;
const int maxn=1e6+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
inline int ask(int x,int y){
	printf("? %d %d\n",x,y);
	fflush(stdout);
	ri ret;
	scanf("%d",&ret);
	return ret;
}
template<typename T>
struct dq{
	int hd,tl;
	T v[maxn];
	inline dq(){hd=1;}
	inline T front(int ex=0){return v[hd+ex];}
	inline T back(int ex=0){return v[tl-ex];}
	inline void pop_front(){++hd;}
	inline void pop_back(){--tl;}
	inline void push(T k){v[++tl]=k;}
	inline int size(){return tl-hd+1;}
	inline void clear(){hd=1,tl=0;}
};
dq<int>q;
int t_case;
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		int n;
		scanf("%d",&n);
		q.clear();
		for(ri i=1;i<=1<<n;++i)q.push(i);
		while(q.size()>1){
			if(q.size()==2){
				ri k=ask(q.front(),q.front(1));
				assert(k);
				if(k&1){
					ri q0=q.front(0);
					q.clear();
					q.push(q0);
				}
				else{
					ri q1=q.front(1);
					q.clear();
					q.push(q1);
				}
			}
			else{
				ri k=ask(q.front(0),q.front(2));
				if(!k){
					ri kk=ask(q.front(1),q.front(3));
					assert(kk);
					if(kk&1){
						ri q1=q.front(1);
						q.pop_front(),q.pop_front(),q.pop_front(),q.pop_front();
						q.push(q1);
					}
					else{
						ri q3=q.front(3);
						q.pop_front(),q.pop_front(),q.pop_front(),q.pop_front();
						q.push(q3);
					}
				}
				else if(k&1){
					ri kk=ask(q.front(0),q.front(3));
					assert(kk);
					if(kk&1){
						ri q0=q.front(0);
						q.pop_front(),q.pop_front(),q.pop_front(),q.pop_front();
						q.push(q0);
					}
					else{
						ri q3=q.front(3);
						q.pop_front(),q.pop_front(),q.pop_front(),q.pop_front();
						q.push(q3);
					}
				}
				else{
					ri kk=ask(q.front(1),q.front(2));
					assert(kk);
					if(kk&1){
						ri q1=q.front(1);
						q.pop_front(),q.pop_front(),q.pop_front(),q.pop_front();
						q.push(q1);
					}
					else{
						ri q2=q.front(2);
						q.pop_front(),q.pop_front(),q.pop_front(),q.pop_front();
						q.push(q2);
					}
				}
			}
		}
		printf("! %d\n",q.front());
		fflush(stdout);
	}
	return 0;
}