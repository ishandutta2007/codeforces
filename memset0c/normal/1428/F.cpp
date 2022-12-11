#include<bits/stdc++.h>

namespace mem{ //v2.1.4 => size: 14.30KiB
  #define MEM_IO
  #define MEM_MATH
  #define MEM_UTILS
  #define MEM_MODINT
  #define MEM_RANDOM
  #define MEM_STDVAL
  #define MEM_LOGGER
  #define MEM_CONTAINER
  #ifdef memset0
  #else
    #define MEM_FASTIO
  #endif

  #ifdef __SIZEOF_INT128__
    #define MEM_INT128
  #endif

  #define __integer_mapper(func)       \
        func(int)                      \
        func(unsigned int)             \
        func(long long int)            \
        func(unsigned long long int)
  #define __float_mapper(func)         \
        func(float)                    \
        func(double)                   \
        func(long double)
    
    namespace stdval{
  #ifdef MEM_STDVAL
      using i32=int;
      using i64=long long int;
      using u32=unsigned int;
      using u64=unsigned long long int;
      using f32=float;
      using f64=double;
      using f96=long double;
    #ifdef MEM_INT128
      using i128=__int128_t;
      using u128=__uint128_t;
    #endif
  #endif
    }
    
    namespace utils{
  #ifdef MEM_UTILS
      using std::cin;
      using std::tie;
      using std::get;
      using std::cout;
      using std::cerr;
      using std::endl;
      using std::swap;
      using std::sort;
      using std::unique;
      using std::reverse;
      using std::shuffle;
      using std::function;
      using std::make_pair;
      using std::make_tuple;
      using std::accumulate;
      using std::lower_bound;
      using std::upper_bound;
      using std::max_element;
      using std::min_element;
  #endif
    }
    
    namespace random{
  #ifdef MEM_RANDOM
      const int LuckyNumber=20040726; // Kanbe Kotori's Birthday
      std::mt19937 rng(LuckyNumber^std::chrono::steady_clock::now().time_since_epoch().count());
      std::mt19937_64 rng64(LuckyNumber^std::chrono::steady_clock::now().time_since_epoch().count());
      
      template<class T> inline T rand(T l,T r){return std::uniform_int_distribution<T>(l,r)(rng);}
      template<class T> inline T rand64(T l,T r){return std::uniform_int_distribution<T>(l,r)(rng);}
  #endif
    }
    
    namespace modint{
  #ifdef MEM_MODINT
      template<const int mod> struct Z{
        int x;
        inline Z(){x=0;}
        inline Z(int t){x=t;}
        
        inline void operator-=(Z a){(x-=a.x)<0&&(x+=mod);}
        inline void operator+=(Z a){(x+=a.x)>=mod&&(x-=mod);}
        inline void operator*=(Z a){x=(long long)x*a.x%mod;}
        
        friend inline Z operator*(Z a,Z b){return (long long)a.x*b.x%mod;}
        friend inline Z operator-(Z a,Z b){return ((a.x-=b.x)<0&&(a.x+=mod)),a;}
        friend inline Z operator+(Z a,Z b){return ((a.x+=b.x)>=mod&&(a.x-=mod)),a;}
      };
      
      template<const int mod> inline Z<mod> finv(Z<mod> x){
        if(x.x<2)return x;
        return (mod-mod/x.x)*finv(mod%x.x);
      }
      template<const int mod> inline Z<mod> fpow(Z<mod> a,int b){
        Z <mod> s=1;
        for(;b;b>>=1,a=a*a)
          if(b&1)s=s*a;
        return s;
      }
      
      template<const int mod> inline void init_inverse(int n,Z<mod> *inv){
        inv[0]=inv[1]=1;
        for(int i=2;i<n;i++)inv[i]=(mod-mod/i)*inv[mod%i];
      }
      template<const int mod> inline void init_factorial(int n,Z<mod> *fac,Z<mod> *ifac){
        fac[0]=1,init_inverse(n,ifac);
        for(int i=1;i<n;i++)fac[i]=fac[i-1]*i,ifac[i]=ifac[i-1]*ifac[i];
      }
    }
    
    namespace io{
      template<const int mod> inline void read(modint::Z<mod> &x){read(x.x);}
      template<const int mod> inline void print(modint::Z<mod> x){print(x.x);}
  #endif
    }
    
    namespace math{
  #ifdef MEM_MATH
      using std::max;
      using std::min;
      template<class T> inline T abs(T x){return x<0?-x:x;}
      template<class T> inline T gcd(T n,T m){return m?gcd(m,n%m):n;}
      template<class T> inline T lcm(T n,T m){return n/gcd(n,m)*m;}
      
      template<const stdval::u64 p> struct FastDiv{
        stdval::u64 t,i;
        inline FastDiv():t(stdval::u64(-1)/p),i(mul_inv(p)){}
        
        inline bool divide(stdval::u64 n){return n*i<=t;}
        inline bool divide(stdval::i64 n){return stdval::u64(n<0?-n:n)*i<=t;}
        inline stdval::u64 mul_inv(stdval::u64 n){
          stdval::u64 x=n;
          for(int i=0;i<5;++i)x*=2-n*x;
          return x;
        }
      };
    
    #ifdef MEM_INT128
      template<const stdval::u64 b> struct FastMod{
        stdval::u64 m;
        inline FastMod():m(stdval::u64((stdval::u128(1)<<64)/b)){}
        
        inline stdval::u64 reduce(stdval::u64 a){
          stdval::u64 q=(stdval::u64)((stdval::u128(m)*a)>>64);
          stdval::u64 r=a-q*b;
          return r>=b?r-b:r;
        }
      };
    #endif
  #endif
    }
    
    namespace container{
  #ifdef MEM_CONTAINER
      using std::pair;
      using std::tuple;
      using std::set;
      using std::unordered_set;
      using std::map;
      using std::unordered_map;
      using std::queue;
      using std::stack;
      using std::priority_queue;
      
      using std::tie;
      using std::get;
      using std::make_pair;
      using std::make_tuple;
      
      template<class T> struct vector:std::vector<T>{
        using std::vector<T>::vector;
        vector():std::vector<T>(){}
        vector(const std::vector<T> &plain):std::vector<T>(plain){}
        
        inline void sort(){std::sort(this->begin(),this->end());}
        inline void concat(const vector &rhs){this->insert(this->end(),rhs.begin(),rhs.end());}
        inline bool includes(const T &x) const{return std::find(this->begin(),this->end(),x)!=this->end();}
        template<class Function> inline void forEach(Function func){for(const auto &it:*this)func(it);}
        
        inline vector slice(int l,int r) const{
          if(l>r)return {};
          if(r<this->size())return vector(this->begin()+l,this->begin()+r);
          vector<int> rsp=(this->begin()+l,this->end());
          return rsp.resize(r-l),rsp;
        }
        
        inline void from(const std::set<T> &src){
          this->resize(src.size());
          auto it=this->begin();
          for(const T e:src)*it++=e;
        }
        
        template<class R,class Function> inline vector<R> _map(Function func) const{
          vector <R> res(this->size());
          for(size_t i=0;i<this->size();i++)
            res[i]=func(this->operator[](i));
          return res;
        }
        template<class R> inline vector<R> map(R func(T)) const{return this->_map<R>(func);}
        template<class R> inline vector<R> map(const std::function<R(T)> &func) const{return this->_map<R>(func);}
      };
      
      struct string:std::string{
        using std::string::string;
        string():std::string(""){}
        string(const std::string &plain):std::string(plain){}
        
        template<class T> inline string join(const vector<T> &vet) const;
        
        vector<string> split(const string &dim) const{
          if(this->empty())return {};
          char *src=new char[this->length()+1];
          strcpy(src,this->c_str());
          char *tar=new char[dim.length()+1];
          strcpy(tar,dim.c_str());
          vector <string> rsp;
          for(char *pos=strtok(src,tar);pos;pos=strtok(nullptr,tar))
            rsp.push_back(string(pos));
          delete[] src;
          delete[] tar;
          return rsp;
        }
        
        template<class... Args> static inline string format(const char *fm,Args... args){
          int len=snprintf(nullptr,0,fm,args...);
          char *buf=new char[len+1];
          snprintf(buf,len+1,fm,args...);
          string str(buf);
          delete[] buf;
          return str;
        }
        template<class... Args> static inline string format(const string &fm,Args... args){
          return format(fm.c_str(),args...);
        }
      };
    
    #define __to_string(T)                 \
      inline string to_string(const T &x){ \
        return std::to_string(x);          \
      }
      __float_mapper(__to_string)
      __integer_mapper(__to_string)
    #undef __to_string
      
      inline string to_string(const string &s){return s;}
      inline string to_string(const char *s){return string(s);}
      inline string to_string(const std::string &s){return string(s);}
      
      template<const int mod> inline string to_string(const mem::modint::Z<mod> &v){return std::to_string(v.x);}
      
      template<class T> inline string to_string(const vector<T> &ctn){return "["+string(",").join(ctn)+"]";}
      template<class T> inline string to_string(const set<T> &ctn){
        string result="{";
        bool flag=false;
        for(const auto &it:ctn){
          if(flag)result+=",";
          flag=true;
          result+=to_string(it);
        }
        return result+"}";
      }
      template<class T1,class T2> inline string to_string(const map<T1,T2> &ctn){
        string result="{";
        bool flag=false;
        for(const auto &it:ctn){
          if(flag)result+=",";
          flag=true;
          result+=to_string(it.first)+":"+to_string(it.second);
        }
        return result+"}";
      }
      
      template<class T> inline string string::join(const vector<T> &vet) const{
        if(!vet.size())return "";
        string res=to_string(vet[0]);
        for(size_t i=1;i<vet.size();i++){
          res+=*this;
          res+=to_string(vet[i]);
        }
        return res;
      }
      
      inline string operator "" _s(const char *s){return string(s);}
      inline string operator "" _s(const char *s,size_t len){return string(s,len);}
      inline string operator "" _s(long double x){return to_string(x);}
      inline string operator "" _s(unsigned long long int x){return to_string(x);}
  #endif
    }
    
    namespace io{
  #ifdef MEM_IO
    #ifdef MEM_FASTIO
      namespace fastio{
        const int BUFFER=1<<18;
        char ibuf[BUFFER],*iS,*iT;
        inline int getc(){
          if(iS==iT){
            iT=(iS=ibuf)+fread(ibuf,1,BUFFER,stdin);
            return iS==iT?EOF:*iS++;
          }else{
            return *iS++;
          }
        }
        char obuf[BUFFER],*oS=obuf,*oT=oS+BUFFER-1;
        inline void flush(){
          fwrite(obuf,1,oS-obuf,stdout);
          oS=obuf;
        }
        inline void putc(int x){
          *oS++=x;
          if(oS==oT)flush();
        }
        struct Flusher{~Flusher(){flush();}}flusher;
      }
      using fastio::getc;
      using fastio::putc;
    #else
      inline int getc(){return getchar();}
      inline void putc(int c){putchar(c);}
    #endif
      
      template<class T> inline void readDigit(T &x){
        x=getc();
        while(!isdigit(x))x=getc();
      }
      inline int readDigit(){
        int x;
        readDigit(x);
        return x;
      }
      template<class T> inline void readAlpha(T &x){
        x=getc();
        while(!isalpha(x))x=getc();
      }
      inline int readAlpha(){
        int x;
        readAlpha(x);
        return x;
      }
    
    #define __read(T)                             \
        inline void read(T &x) {                  \
          x=0; bool f=0; char c=getc();           \
          while(!isdigit(c))f^=c=='-',c=getc();   \
          while(isdigit(c))x=x*10+c-'0',c=getc(); \
          if(f)x=-x;                              \
        }
      __integer_mapper(__read)
    #undef __read
      
      inline void read(char &x){x=getc();}
      inline void read(char *s){
        char c=getc();
        while(~c&&!isspace(c))*s++=c,c=getc();
        *s++='\0';
      }
      inline void read(container::string &s){
        char c=getc();
        s="";
        while(~c&&!isspace(c))s+=c,c=getc();
      }
      
      template<class T=int> inline T read(){
        T x;
        read(x);
        return x;
      }
      template<class T,class... Args> inline void read(T &x,Args &... args){
        read(x),read(args...);
      }
    
    #define __print(T)           \
        inline void print(T x){  \
          if(x<0)putc('-'),x=-x; \
          if(x>9)print(x/10);    \
          putc('0'+x%10);        \
        }
      __integer_mapper(__print)
    #undef __print
      
      inline void print(char x){putc(x);}
      inline void print(const char *s){
        int len=strlen(s);
        for(int i=0;i<len;i++)putc(s[i]);
      }
      inline void print(const container::string &s){
        for(int i=0;i<s.length();i++)putc(s[i]);
      }
      
      template<class T,class... Args> inline void print(const T &x,Args... args){
        print(x),print(args...);
      }
      template<class... Args> inline void println(Args... args){
        print(args...),putc('\n');
      }
      
      template<class... Args> inline void printfm(const char *formatter,Args... arguments){
        print(container::string().format(formatter,arguments...));
      }
      template<class... Args> inline void printfm(const container::string &formatter,Args... arguments){
        print(container::string().format(formatter,arguments...));
      }
  #endif
    }
    
    namespace logger{
  #ifdef MEM_LOGGER
      enum ConsoleColor{
        NOPE=-1,BLACK,RED,GREEN,YELLOW,BLUE,PURPLE,DEEPBLUE
      };
      template<const ConsoleColor color=NOPE,class... Args> inline void log(const char *formatter,Args... args){
        if(~color){
          fprintf(stderr,"\033[%dm",30+color);
          fprintf(stderr,formatter,args...);
          fprintf(stderr,"\033[0m");
        }else{
          fprintf(stderr,formatter,args...);
        }
      }
      template<const ConsoleColor color=NOPE,class... Args> inline void logln(const char *formatter,Args... args){
        if(~color){
          fprintf(stderr,"\033[%dm",30+color);
          fprintf(stderr,formatter,args...);
          fprintf(stderr,"\033[0m\n");
        }else{
          fprintf(stderr,formatter,args...);
          fprintf(stderr,"\n");
        }
      }
      template<class T> inline void logs(const T &x){
        fprintf(stderr,container::to_string(x).c_str());
      }
      template<class T,class... Args> inline void logs(const T &x,Args... args){
        logs(x),logs(args...);
      }
      template<class... Args> inline void logsln(Args... args){
        logs(args...);
        fprintf(stderr,"\n");
      }
  #endif
    }

  #undef __integer_mapper
  #undef __float_mapper
  #undef __string_mapper
  #undef __string_join_mapper
    
    using namespace io;
    using namespace math;
    using namespace utils;
    using namespace modint;
    using namespace random;
    using namespace stdval;
    using namespace logger;
    using namespace container;
} // namespace mem
using namespace mem;

const int N=5e5+10;
int n,a[N],pre[N],nxt[N];
string s;
long long ans;

struct segment{
  int l,r,mid,cnt;
  long long sum;
}p[N<<2];
inline void maintain(int u){
  p[u].cnt=p[u<<1].cnt+p[u<<1|1].cnt;
  p[u].sum=p[u<<1].sum+p[u<<1|1].sum;
}
void build(int u,int l,int r){
  p[u].l=l;
  p[u].r=r;
  p[u].mid=(l+r)>>1;
  if(l==r){
    return;
  }
  build(u<<1,l,p[u].mid);
  build(u<<1|1,p[u].mid+1,r);
}
void update(int u,int k,int x){
  if(p[u].l==p[u].r){
    p[u].cnt+=x;
    p[u].sum+=(long long)x*k;
    return;
  }
  if(k<=p[u].mid){
    update(u<<1,k,x);
  }else{
    update(u<<1|1,k,x);
  }
  maintain(u);
}
void modify(int u,int k,int x){
  if(p[u].l==p[u].r){
    p[u].cnt=x;
    p[u].sum=(long long)x*k;
    return;
  }
  if(k<=p[u].mid){
    modify(u<<1,k,x);
  }else{
    modify(u<<1|1,k,x);
  }
  maintain(u);
}
int queryCnt(int u,int l,int r){
  if(p[u].l==l&&p[u].r==r){
    return p[u].cnt;
  }
  if(r<=p[u].mid){
    return queryCnt(u<<1,l,r);
  }else if(l>p[u].mid){
    return queryCnt(u<<1|1,l,r);
  }else{
    return queryCnt(u<<1,l,p[u].mid)+queryCnt(u<<1|1,p[u].mid+1,r);
  }
}
long long querySum(int u,int l,int r){
  if(p[u].l==l&&p[u].r==r){
    return p[u].sum;
  }
  if(r<=p[u].mid){
    return querySum(u<<1,l,r);
  }else if(l>p[u].mid){
    return querySum(u<<1|1,l,r);
  }else{
    return querySum(u<<1,l,p[u].mid)+querySum(u<<1|1,p[u].mid+1,r);
  }
}

inline long long eval(int x){
  return (x?(long long)queryCnt(1,0,x-1)*x:0)+querySum(1,x,n);
}

int main(){
#ifdef memset0
  freopen("1.in","r",stdin);
#endif
  read(n,s);
  for(int i=1;i<=n;i++){
    a[i]=s[i-1]=='1';
  }
  for(int i=1;i<=n;i++)
    if(a[i]&&a[i-1]){
      pre[i]=pre[i-1];
    }else if(a[i]){
      pre[i]=i;
    }else{
      pre[i]=-1;
    }
  for(int i=n;i>=1;i--)
    if(a[i]&&a[i+1]){
      nxt[i]=nxt[i+1];
    }else if(a[i]){
      nxt[i]=i;
    }else{
      nxt[i]=-1;
    }
  build(1,0,n);
  for(int r=1;r<=n;r++){
    if(a[r]){
      int len=r-pre[r]+1;
      ans+=(long long)(len+1)*len/2;
      ans+=eval(len);
    }else{
      if(a[r-1]){
        int len=r-pre[r-1];
        // log<BLUE>("add black (len=%d)\n",len);
        int cnt=queryCnt(1,0,len-1);
        for(int i=0;i<len;i++){
          modify(1,i,0);
        }
        update(1,len,cnt);
        for(int i=1;i<=len;i++){
          update(1,i,1);
        }
      }
      update(1,0,1);
      ans+=eval(0);
    }
    // log<RED>("%d : %lld\n",r,ans);
  }
  printf("%lld\n",ans);
}