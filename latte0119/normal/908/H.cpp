    #include<bits/stdc++.h>
    using namespace std;
     
    #define int long long
     
    #define rep(i,n) for(int i=0;i<(n);i++)
    #define pb push_back
    #define all(v) (v).begin(),(v).end()
    #define fi first
    #define se second
    typedef vector<int>vint;
    typedef pair<int,int>pint;
    typedef vector<pint>vpint;
     
    template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
    template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}
     
    /*
    time: less than O(NlogN+Q) amortized
    based on weighted union heuristic
    */
    struct UnionFindTree{
        vector<int>par,sz;
        UnionFindTree(int n){
            par.resize(n);
            sz.resize(n);
            for(int i=0;i<n;i++){
                par[i]=i;
                sz[i]=1;
            }
        }
        int find(int x){
            return x==par[x]?x:par[x]=find(par[x]);
        }
        void unite(int x,int y){
            x=find(x);y=find(y);
            if(x==y)return;
            if(sz[x]<sz[y])swap(x,y);
            sz[x]+=sz[y];
            par[y]=x;
        }
        bool areSame(int x,int y){
            return find(x)==find(y);
        }
        int size(int x){
            return sz[find(x)];
        }
    };
     
     
    /*
    GF(p)
    inverse:O(log p) based on Fermat's little theorem (a^(p-1)=1 mod p)
    */
     
    template<int32_t mod>
    struct ModInt{
    	int32_t a;
    	inline int32_t normalize(int64_t x){
    		x%=mod;
    		if(x<0)x+=mod;
    		return x;
    	}
    	ModInt(const int64_t a=0):a(normalize(a)){}
     
    	ModInt& operator+=(const ModInt &x){
    		a+=x.a;
    		if(a>=mod)a-=mod;
    		return *this;
    	}
    	ModInt& operator-=(const ModInt &x){
    		a-=x.a;
    		if(a<0)a+=mod;
    		return *this;
    	}
    	ModInt& operator*=(const ModInt &x){
    		a=(int64_t)a*x.a%mod;
    		return *this;
    	}
    	ModInt& operator/=(const ModInt &x){
    		*this*=x.inv();
    		return *this;
    	}
     
    	ModInt operator+(const ModInt x){return ModInt(*this)+=x;}
    	ModInt operator-(const ModInt x){return ModInt(*this)-=x;}
    	ModInt operator*(const ModInt x){return ModInt(*this)*=x;}
    	ModInt operator/(const ModInt x){return ModInt(*this)/=x;}
    	bool operator==(const ModInt x){return a==x.a;}
    	bool operator!=(const ModInt x){return a!=x.a;}
     
    	ModInt operator-(){return ModInt(0)-ModInt(*this);}
    	ModInt pow(int64_t ex)const{
    		int64_t x=a;
    		int64_t res=1;
    		while(ex){
    			if(ex&1)res=res*x%mod;
    			x=x*x%mod;
    			ex>>=1;
    		}
    		return ModInt(res);
    	}
    	ModInt inv()const{return pow(mod-2);}
    };
     
    template<int32_t mod>
    istream& operator>>(istream& in,ModInt<mod>& a){
    	return (in>>a.a);
    }
    template<int32_t mod>
    ostream& operator<<(ostream& out,const ModInt<mod>& a){
    	return (out<<a.a);
    }
     
     
     
    using mint=ModInt<1000000007>;
     
    int pc[1<<23];
     
    signed main(){
        rep(i,1<<23)pc[i]=__builtin_popcount(i);
        int N;cin>>N;
        vector<string>A(N);
        rep(i,N)cin>>A[i];
        
        UnionFindTree uf(N);
        rep(i,N)for(int j=i+1;j<N;j++)if(A[i][j]=='A')uf.unite(i,j);
        
        rep(i,N)for(int j=i+1;j<N;j++)if(A[i][j]=='X'&&uf.areSame(i,j)){
            cout<<-1<<endl;
            return 0;
        }
        
        
        int ans=N;
        vector<int>rs;
        rep(i,N){
            if(uf.find(i)!=i)continue;
            if(uf.size(i)==1){
                continue;
            }
            rs.pb(i);
        }
        
        sort(all(rs));
        
        int n=rs.size();
        
        vector<mint>b(1<<n);
        rep(i,N){
            for(int j=i+1;j<N;j++){
                if(A[i][j]=='X'&&uf.size(i)!=1&&uf.size(j)!=1){
                    int x=lower_bound(all(rs),uf.find(i))-rs.begin();
                    int y=lower_bound(all(rs),uf.find(j))-rs.begin();
                    b[(1<<x)|(1<<y)]=1;
                }
            }
        }
        
        
        rep(i,n){
            rep(j,1<<n){
                if(!(j>>i&1))b[j|(1<<i)]+=b[j];
            }
        }
        
        
        vector<mint>c(1<<n);
        rep(i,1<<n)if(b[i]==0)c[i]=1;
        
        
        
        rep(i,n){
            rep(j,1<<n){
                if(!(j>>i&1))c[j|(1<<i)]+=c[j];
            }
        }
        
        
        rep(i,1<<n)b[i]=1;
        
        for(int i=0;;i++){
            mint f=0;
            for(int i=0;i<(1<<n);i++){
                if((n-pc[i])&1)f-=b[i];
            
                else f+=b[i];
                
                b[i]*=c[i];
            }
            if(f!=0){
                ans+=i-1;
                break;
            }
        }
        
        cout<<ans<<endl;
        return 0;
    }