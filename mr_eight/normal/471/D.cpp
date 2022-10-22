#include <iostream>
#include <vector>
#define F(i,a,b) for(register int i=a,i##end=b;i<=i##end;++i)
using namespace std;
vector<int>S,s;
int f[1000002],k,n,m,lst,now;
namespace fastIO {
	template<class T>
	inline void read(T &x) {
		x=0;
		bool fu=0;
		char ch=0;
		while(ch>'9'||ch<'0') {
			ch=getchar();
			if(ch=='-')fu=1;
		}
		while(ch<='9'&&ch>='0') x=(x*10-48+ch),ch=getchar();
		if(fu)x=-x;
	}
	inline int read() {
		int x=0;
		bool fu=0;
		char ch=0;
		while(ch>'9'||ch<'0') {
			ch=getchar();
			if(ch=='-')fu=1;
		}
		while(ch<='9'&&ch>='0') x=(x*10-48+ch),ch=getchar();
		return fu?-x:x;
	}
	char _n_u_m_[40];
	template<class T>
	inline void write(T x ) {
		if(x==0){
			putchar('0');
			return;
		}
		T tmp = x > 0 ? x : -x ;
		if( x < 0 ) putchar('-') ;
		register int cnt = 0 ;
		while( tmp > 0 ) {
			_n_u_m_[ cnt ++ ] = tmp % 10 + '0' ;
			tmp /= 10 ;
		}
		while( cnt > 0 ) putchar(_n_u_m_[ -- cnt ]) ;
	}
	template<class T>
	inline void write(T x ,char ch) {
		write(x);
		putchar(ch);
	}
}
using namespace fastIO;
int ans;
int main(){
	read(n),read(m);
    read(lst);
    if(m==1){
    	cout<<n;
    	return 0;
	}
    F(i,2,n){
    	read(now);
    	S.push_back(now-lst);
    	lst=now;
	}read(lst);F(i,2,m){
    	read(now);
    	s.push_back(now-lst);
    	lst=now;
	}
    f[0]=-1,f[1]=0;
    F(i,1,s.size()-1){k=i;   	
    	while(k>=0){
    		if(s[i]==s[f[k]]){
    			f[i+1]=f[k]+1;
    			break;
			}else k=f[k];
		}   	
	}register int i=0,j=0;	
	while(i<S.size())
		if(j==s.size()){
			ans++;
			j=f[j];
		}
		else if(j==-1||S[i]==s[j])i++,j++;
		else j=f[j];
	if(j==s.size())ans++;		
	cout<<ans;
    return 0;
}