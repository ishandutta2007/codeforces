#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt")
#undef ONLINE_JUDGE
#include<bits/stdc++.h>
#define Luogu 1
#define Cf 2
#define At 3
#define Other 4
#define No 5
//settings-settings-settings-settings-settings-settings-settings-settings-settings-settings-settings-settings-settings-settings-settings-settings-settings-settings
                                                                    #define use_qp                 0
                                                                    #define use_inv                0
                                                                    #define use_C                  0
                                                                    #define use_matrix             0
                                                                    #define use_modint             0
                                                                    #define use_pbds               0
                                                                    #define use_BIT                0
                                                                    #define use_seg                0
                                                                    #define use_long_long          1
                                                                    #define use_fastio             1
                                                                    #define use_multiple_test_data 1
                                                                    #define ONLINE_JUDGE           Luogu
                                                                    #define me(x,y)                memset(x,y,sizeof(x))
                                                                    #define ex(x)                  return cout<<x<<endl,void(0)
                                                                    #define length_of_double_cout  10
//settings-settings-settings-settings-settings-settings-settings-settings-settings-settings-settings-settings-settings-settings-settings-settings-settings-settings
using namespace std;
#if ONLINE_JUDGE==No
#undef ONLINE_JUDGE
#endif
#if ONLINE_JUDGE==Cf or ONLINE_JUDGE==At
#pragma GCC optimize(3)
#endif
#ifdef ONLINE_JUDGE
	namespace Fread{const int SIZE=1<<16;char buf[SIZE],*S,*T;inline char getchar(){if(S==T){T=(S=buf)+fread(buf,1,SIZE,stdin);if(S==T)return'\n';}return *S++;}}namespace Fwrite{const int SIZE=1<<16;char buf[SIZE],*S=buf,*T=buf+SIZE;inline void flush(){fwrite(buf,1,S-buf,stdout);S=buf;}inline void putchar(char c){*S++=c;if(S==T)flush();}struct NTR{~NTR(){flush();}}ztr;}
    #define getchar Fread::getchar
	#define putchar Fwrite::putchar
#endif
#if use_pbds==1
#if ONLINE_JUDGE==Luogu
#include<bits/extc++.h>
#else
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#include<ext/pb_ds/trie_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#endif
using namespace __gnu_pbds;
#endif
#define Setprecision length_of_double_cout
namespace Fastio{struct Reader{template<typename T>Reader&operator>>(T&x){char c=getchar();short f=1;while(c<'0'||c>'9'){if(c=='-')f*=-1;c=getchar();}x=0;while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+(c^48);c=getchar();}x*=f;return *this;}Reader&operator>>(double&x){char c=getchar();short f=1,s=0;x=0;double t=0;while((c<'0'||c>'9')&&c!='-'&&c!='.'){if(c=='-')f*=-1;c=getchar();}while(c>='0'&&c<='9'&&c!='.')x=x*10+(c^48),c=getchar();if(c=='.')c=getchar();else return x*=f,*this;while(c>='0'&&c<='9')t=t*10+(c^48),s++,c=getchar();while(s--)t/=10.0;x=(x+t)*f;return*this;}Reader&operator>>(long double&x){char c=getchar();short f=1,s=0;x=0;long double t=0;while((c<'0'||c>'9')&&c!='-'&&c!='.'){if(c=='-')f*=-1;c=getchar();}while(c>='0'&&c<='9'&&c!='.')x=x*10+(c^48),c=getchar();if(c=='.')c=getchar();else return x*=f,*this;while(c>='0'&&c<='9')t=t*10+(c^48),s++,c=getchar();while(s--)t/=10.0;x=(x+t)*f;return*this;}Reader&operator>>(__float128&x){char c=getchar();short f=1,s=0;x=0;__float128 t=0;while((c<'0'||c>'9')&&c!='-'&&c!='.'){if(c=='-')f*=-1;c=getchar();}while(c>='0'&&c<='9'&&c!='.')x=x*10+(c^48),c=getchar();if(c=='.')c=getchar();else return x*=f,*this;while(c>='0'&&c<='9')t=t*10+(c^48),s++,c=getchar();while(s--)t/=10.0;x=(x+t)*f;return*this;}Reader&operator>>(char&c){c=getchar();while(c=='\n'||c==' '||c=='\r')c=getchar();return *this;}Reader&operator>>(char*str){int len=0;char c=getchar();while(c=='\n'||c==' '||c=='\r')c=getchar();while(c!='\n'&&c!=' '&&c!='\r')str[len++]=c,c=getchar();str[len]='\0';return*this;}Reader&operator>>(std::string&str){char c=getchar();while(c=='\n'||c==' '||c=='\r')c=getchar();while(c!='\n'&&c!=' '&&c!='\r')str.push_back(c),c=getchar();return*this;}Reader(){}}cin;const char endl='\n';struct Writer{typedef __int128 mxdouble;template<typename T>Writer&operator<<(T x){if(x==0)return putchar('0'),*this;if(x<0)putchar('-'),x=-x;static int sta[45];int top=0;while(x)sta[++top]=x%10,x/=10;while(top)putchar(sta[top]+'0'),--top;return*this;}Writer&operator<<(double x){if(x<0)putchar('-'),x=-x;mxdouble _=x;x-=(double)_;static int sta[45];int top=0;while(_)sta[++top]=_%10,_/=10;if(!top)putchar('0');while(top)putchar(sta[top]+'0'),--top;putchar('.');for(int i=0;i<Setprecision;i++)x*=10;_=x;while(_)sta[++top]=_%10,_/=10;for(int i=0;i<Setprecision-top;i++)putchar('0');while(top)putchar(sta[top]+'0'),--top;return*this;}Writer&operator<<(long double x){if(x<0)putchar('-'),x=-x;mxdouble _=x;x-=(long double)_;static int sta[45];int top=0;while(_)sta[++top]=_%10,_/=10;if(!top)putchar('0');while(top)putchar(sta[top]+'0'),--top;putchar('.');for(int i=0;i<Setprecision;i++)x*=10;_=x;while(_)sta[++top]=_%10,_/=10;for(int i=0;i<Setprecision-top;i++)putchar('0');while(top)putchar(sta[top]+'0'),--top;return*this;}Writer&operator<<(__float128 x){if(x<0)putchar('-'),x=-x;mxdouble _=x;x-=(__float128)_;static int sta[45];int top=0;while(_)sta[++top]=_%10,_/=10;if(!top)putchar('0');while(top)putchar(sta[top]+'0'),--top;putchar('.');for(int i=0;i<Setprecision;i++)x*=10;_=x;while(_)sta[++top]=_%10,_/=10;for(int i=0;i<Setprecision-top;i++)putchar('0');while(top)putchar(sta[top]+'0'),--top;return*this;}Writer&operator<<(char c){putchar(c);return*this;}Writer&operator<<(char*str){int cur=0;while(str[cur])putchar(str[cur++]);return *this;}Writer&operator<<(const char*str){int cur=0;while(str[cur])putchar(str[cur++]);return*this;}Writer&operator<<(std::string str){int st=0,ed=str.size();while(st<ed)putchar(str[st++]);return*this;}Writer(){}}cout;}
#if use_fastio==1
#define cin Fastio :: cin
#define cout Fastio :: cout
#define endl Fastio :: endl
#endif
#if use_long_long==1
#define int long long
#endif
//constants-constants-constants-constants-constants-constants-constants-constants-constants-constants-constants-constants-constants-constants-constants-constants
                                                                    #define N                      500005
                                                                    #define eps                    1e-10
                                                                    #define p                      998244353
                                                                    //#undef N
                                                                    #undef p
//constants-constants-constants-constants-constants-constants-constants-constants-constants-constants-constants-constants-constants-constants-constants-constants
#if (use_qp==1||use_C==1||use_inv==1)
#ifdef p
int qp(int x,int n=p-2,int P=p){int r=1;while(n){if(n&1)r=r*x%P;x=x*x%P,n>>=1;}return r;}
#else
int qp(int x,int n,int P){int r=1;while(n){if(n&1)r=r*x%P;x=x*x%P,n>>=1;}return r;}
#endif
#endif
#if (use_C==1||use_inv==1)
int fac[N+100],ifac[N+100];
void init(int n,int P=p){fac[0]=1;for(int x=1;x<=n;x++)fac[x]=fac[x-1]*x%P;ifac[n]=qp(fac[n],P-2,P);for(int x=n;x>=1;x--)ifac[x-1]=ifac[x]*x%P;}
int C(int x,int y,int P=p){if(x<y||y<0)return 0;return fac[x]*ifac[y]%P*ifac[x-y]%P;}
int iC(int x,int y,int P=p){if(x<y||y<0)return 0;return ifac[x]*fac[y]%P*fac[x-y]%P;}
int inv(int x,int P=p){return iC(x,1,P);}
#endif
#if use_modint==1
#define mod 20170408
struct modint{
	int x;
	modint(int o=0){x=o%mod;}
	modint &operator = (int o){return x=o%mod,*this;}
	modint &operator +=(modint o){return x=x+o.x>=mod?x+o.x-mod:x+o.x,*this;}
	modint &operator -=(modint o){return x=x-o.x<0?x-o.x+mod:x-o.x,*this;}
	modint &operator *=(modint o){return x=1ll*x*o.x%mod,*this;}
	modint &operator +=(int o){return x=x+(o%mod)>=mod?x+(o%mod)-mod:x+(o%mod),*this;}
	modint &operator -=(int o){return x=x-(o%mod)<0?x-(o%mod)+mod:x-(o%mod),*this;}
	modint &operator *=(int o){return x=1ll*x*(o%mod)%mod,*this;}
	modint &operator ^=(int b){
		modint a=*this,c=1;
		for(;b;b>>=1,a*=a)if(b&1)c*=a;
		return x=c.x,*this;
	}
	modint &operator /=(modint o){return *this *=o^=mod-2;}
    modint &operator /=(int o){return *this *=modint(o)^=mod-2;}
	friend modint operator +(modint a,modint b){return a+=b;}
	friend modint operator -(modint a,modint b){return a-=b;}
	friend modint operator *(modint a,modint b){return a*=b;}
	friend modint operator /(modint a,modint b){return a/=b;}
	friend modint operator +(modint a,int b){return a+=b;}
	friend modint operator -(modint a,int b){return a-=b;}
	friend modint operator *(modint a,int b){return a*=b;}
	friend modint operator +(int a,modint b){return b+=a;}
	friend modint operator -(int a,modint b){return -1*(b-=a);}
	friend modint operator *(int a,modint b){return b*=a;}
	friend modint operator ^(modint a,int b){return a^=b;}
	friend bool operator ==(modint a,int b){return a.x==b;}
	friend bool operator !=(modint a,int b){return a.x!=b;}
	friend bool operator <(modint a,int b){return a.x<b;}
	friend bool operator >(modint a,int b){return a.x>b;}
	friend bool operator <=(modint a,int b){return a.x<=b;}
	friend bool operator >=(modint a,int b){return a.x>=b;}
	bool operator ! () {return !x;}
	modint operator - () {return x?mod-x:0;}
	bool operator <(const modint&b)const{return x<b.x;}
	bool operator >(const modint&b)const{return x>b.x;}
	bool operator <=(const modint&b)const{return x<=b.x;}
	bool operator >=(const modint&b)const{return x>=b.x;}
	bool operator ==(const modint&b)const{return x==b.x;}
	bool operator !=(const modint&b)const{return x!=b.x;}
    operator int() const {return x;}
};
inline modint qp(modint x,int y){return x^y;}
inline modint abs(modint x){return x>0?x:-x;}
istream&operator>>(istream&is,modint&m)
{
    int o;
    cin>>o;
    m=o;
	return is;
}
#endif
#if use_matrix==1
#define mttype modint
class Matrix {
private:
	int rows_num,cols_num;
	mttype **p;
	void initialize();//
 
public:
	Matrix(int,int);
	Matrix(int,int,mttype);//
	virtual ~Matrix();//
	Matrix&operator=(const Matrix&);//
	Matrix&operator=(mttype *);//
	Matrix&operator+=(const Matrix&);//+=
	Matrix&operator-=(const Matrix&);//-=
	Matrix&operator*=(const Matrix&);//*=
	Matrix operator*(const Matrix&m)const;
	static Matrix Solve(const Matrix&,const Matrix&);//Ax=b
	void Show() const;//
	void swapRows(int,int);
	mttype det();//
	mttype Point(int i,int j) const;
	static Matrix inv(Matrix);//
	static Matrix eye(int );//
	int row() const;
	int col() const;
	static Matrix T(const Matrix&m);//,
	Matrix gaussianEliminate();//
	friend std::istream&operator>>(std::istream&,Matrix&);//
};
const mttype EPS=1e-10;
void Matrix::initialize(){
	p=new mttype*[rows_num];
	for(int i=0;i<rows_num;++i)p[i]=new mttype[cols_num];
}
Matrix::Matrix(int rows,int cols)
{
	rows_num=rows;
	cols_num=cols;
	initialize();
	for(int i=0;i<rows_num;i++)
	for(int j=0;j<cols_num;j++)
	p[i][j]=0;
}
Matrix::Matrix(int rows,int cols,mttype value)
{
	rows_num=rows;
	cols_num=cols;
	initialize();
	for(int i=0;i<rows_num;i++)
	for(int j=0;j<cols_num;j++)
	p[i][j]=value;
}
Matrix::~Matrix() {
	for(int i=0;i<rows_num;++i)delete[] p[i];
	delete[] p;
}
Matrix&Matrix::operator=(const Matrix&m)
{
	if(this==&m)return *this;
	if(rows_num!=m.rows_num||cols_num!=m.cols_num){
		for(int i=0;i<rows_num;++i)delete[] p[i];
		delete[] p;
		rows_num=m.rows_num;
		cols_num=m.cols_num;
		initialize();
	}
	for(int i=0;i<rows_num;i++)
	for(int j=0;j<cols_num;j++)
	p[i][j]=m.p[i][j];
	return *this;
}
Matrix&Matrix::operator=(mttype *a){
	for(int i=0;i<rows_num;i++)
	for(int j=0;j<cols_num;j++)
	p[i][j]=*(a+i*cols_num+j);
	return *this;
}
Matrix&Matrix::operator+=(const Matrix&m)
{
	for(int i=0;i<rows_num;i++)
	for(int j=0;j<cols_num;j++)
	p[i][j]+=m.p[i][j];
	return *this;
}
Matrix&Matrix::operator-=(const Matrix&m)
{
	for(int i=0;i<rows_num;i++)
	for(int j=0;j<cols_num;j++)
	p[i][j]-=m.p[i][j];
	return *this;
}
Matrix&Matrix::operator*=(const Matrix&m)
{
	Matrix temp(rows_num,m.cols_num);
	for(int i=0;i<temp.rows_num;i++)
	for(int j=0;j<temp.cols_num;j++)
	for(int k=0;k<cols_num;k++)
	temp.p[i][j]+=(p[i][k]*m.p[k][j]);
	*this=temp;
	return *this;
}
Matrix Matrix::operator*(const Matrix&m)const{
	Matrix ba_M(rows_num,m.cols_num,0.0);
	for(int i=0;i<rows_num;i++)
	for(int j=0;j<m.cols_num;j++)
	for(int k=0;k<cols_num;k++)
	ba_M.p[i][j]+=(p[i][k]*m.p[k][j]);
	return ba_M;
}
Matrix Matrix::Solve(const Matrix &A,const Matrix &b)
{
	for(int i=0;i<A.rows_num;i++)
	for(int j=i+1;j<A.rows_num;j++){
		for(int k=i+1;k<A.cols_num;k++){
			A.p[j][k]-=A.p[i][k]*(A.p[j][i]/A.p[i][i]);
			if(abs(A.p[j][k])<EPS)A.p[j][k]=0;
		}
		b.p[j][0]-=b.p[i][0]*(A.p[j][i]/A.p[i][i]);
		if(abs(A.p[j][0])<EPS)A.p[j][0]=0;
		A.p[j][i]=0;
	}
	Matrix x(b.rows_num,1);
	x.p[x.rows_num-1][0]=b.p[x.rows_num-1][0]/A.p[x.rows_num-1][x.rows_num-1];
	if(abs(x.p[x.rows_num-1][0])<EPS)x.p[x.rows_num-1][0]=0;
	for(int i=x.rows_num-2;i>=0;i--){
		mttype sum=0;
		for(int j=i+1;j<x.rows_num;j++)sum+=A.p[i][j]*x.p[j][0];
		x.p[i][0]=(b.p[i][0]-sum)/A.p[i][i];
		if (abs(x.p[i][0])<EPS)x.p[i][0]=0;
	}
	return x;
}
void Matrix::Show() const {
	//cout<<rows_num <<" "<<cols_num<< endl;//
	for(int i=0;i<rows_num;i++){
	for(int j=0;j<cols_num;j++)cout<<p[i][j]<<" ";cout<<endl;}
	cout<<endl;
}
void Matrix::swapRows(int a,int b){a--;b--;swap(p[a],p[b]);}
mttype Matrix::det(){
	mttype ** back_up;
	back_up=new mttype *[rows_num];
	for(int i=0;i<rows_num;i++)back_up[i]=new mttype[cols_num];
	for(int i=0;i<rows_num;i++)for(int j=0;j<cols_num;j++)back_up[i][j]=p[i][j];
	if(rows_num!=cols_num)abort();//
	mttype ans=1;
	for(int i=0;i<rows_num;i++)
	if(abs(p[i][i])<=EPS){
		bool flag=false;
		for(int j=0;(j<cols_num)&&(!flag);j++)
		if((abs(p[i][j])>EPS)&&(abs(p[j][i])>EPS)){
			flag=true;
			for(int k=0;k<cols_num;k++)
			swap(p[i][k],p[j][k]);
		}
		if(flag)return 0;
	}
	for(int i=0;i<rows_num;i++)
	for(int j=i+1;j<rows_num;j++)
	for(int k=i+1;k<cols_num;k++)
	p[j][k]-=p[i][k]*(p[j][i]*p[i][i]);
	for(int i=0;i<rows_num;i++)ans*=p[i][i];
	for(int i=0;i<rows_num;i++)
	for(int j=0;j<cols_num;j++)
	p[i][j]=back_up[i][j];
	return ans;
}
mttype Matrix::Point(int i,int j) const{return this->p[i][j];}
Matrix Matrix::inv(Matrix A){
	if(A.rows_num!=A.cols_num)abort();//
	mttype temp;
	Matrix B=eye(A.rows_num);
	for(int i=0;i<A.rows_num;i++)
	for(int j=0;j<A.cols_num;j++)
	if(abs(A.p[i][j])<=EPS)A.p[i][j]=0;
	for(int i=0;i<A.rows_num;i++)
	if(abs(A.p[i][i])<=EPS){
		bool flag=false;
		for(int j=0;(j<A.rows_num)&&(!flag);j++){
			if((abs(A.p[i][j])>EPS)&&(abs(A.p[j][i])>EPS)){
				flag=true;
				for(int k=0;k<A.cols_num;k++)
				swap(A.p[i][k],A.p[j][k]),swap(B.p[i][k],B.p[j][k]);
			}
		}
		if(!flag)abort();//
	}
	mttype temp_rate;
	for(int i=0;i<A.rows_num;i++)
	for(int j=i+1;j<A.rows_num;j++){
		temp_rate=A.p[j][i]/A.p[i][i];
		for(int k=0;k<A.cols_num;k++)
		A.p[j][k]-=A.p[i][k]*temp_rate,B.p[j][k]-=B.p[i][k]*temp_rate;
		A.p[j][i]=0;
	}
	for(int i=0;i<A.rows_num;i++){
		temp=A.p[i][i];
		for(int j=0;j<A.cols_num;j++)
		A.p[i][j]/=temp,B.p[i][j]/=temp;
	}
	for(int i=A.rows_num-1;i>=1;i--)
	for(int j=i-1;j>=0;j--){
		temp=A.p[j][i];
		for(int k=0;k<A.cols_num;k++)
		A.p[j][k]-=A.p[i][k]*temp,B.p[j][k]-=B.p[i][k]*temp;
	}
	return B;
}
Matrix Matrix::eye(int n){
	Matrix A(n,n);
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	if(i==j)A.p[i][j]=1;
	else A.p[i][j]=0;
	return A;
}
int Matrix::row() const{return rows_num;}
int Matrix::col() const{return cols_num;}
Matrix Matrix::T(const Matrix&m)
{	int col_size=m.col(),row_size=m.row();
	Matrix mt(col_size,row_size);
	for(int i=0;i<row_size;i++)
	for(int j=0;j<col_size;j++)
	mt.p[j][i]=m.p[i][j];
	return mt;
}
Matrix Matrix::gaussianEliminate()
{
	Matrix Ab(*this);
	int rows=Ab.rows_num,cols=Ab.cols_num,Acols=cols-1,i=0,j=0;
	while(i<rows)
	{
		bool flag=false;
		while(j<Acols&&!flag)
		{
			if(Ab.p[i][j]!=0)flag=true;
			else{
				int max_row=i;
				mttype max_val=0;
				for(int k=i+1;k<rows;++k)
				{
					mttype cur_abs=Ab.p[k][j]>=0?Ab.p[k][j]:-1*Ab.p[k][j];
					if (cur_abs>max_val)max_row=k,max_val=cur_abs;
				}
				if (max_row!=i)Ab.swapRows(max_row,i),flag=true;
				else j++;
			}
		}
		if (flag)
		{
			for (int t=i+1;t<rows;t++){
				for (int s=j+1;s<cols;s++){
					Ab.p[t][s]=Ab.p[t][s]-Ab.p[i][s]*(Ab.p[t][j]/Ab.p[i][j]);
					if(abs(Ab.p[t][s])<EPS)Ab.p[t][s]=0;
				}
				Ab.p[t][j]=0;
			}
		}
		i++;
		j++;
	}
	return Ab;
}
istream&operator>>(istream&is,Matrix&m)
{
	for(int i=0;i<m.rows_num;i++)for(int j=0;j<m.cols_num;j++)is>>m.p[i][j];
	return is;
}
Matrix qp(Matrix x,int n){Matrix r=x;n--;while(n){if(n&1)r=r*x;x=x*x,n>>=1;}return r;}
#endif
#if use_BIT==1
struct BIT
{
    int BIT_a[N],BIT_b[N];
    BIT(){memset(BIT_a,0,sizeof(BIT_a));memset(BIT_b,0,sizeof(BIT_b));}
    void Add_a(int n,int u,int U=N){for(int x=n;x<=U;x+=x&-x)BIT_a[x]+=u;}
    void Add_b(int n,int u,int U=N){for(int x=n;x<=U;x+=x&-x)BIT_b[x]+=u;}
    void add(int l,int r,int u,int U=N){Add_a(l,u),Add_a(r+1,-u);Add_b(l,l*u),Add_b(r+1,-(r+1)*u);}
    int Query_a(int n){int r=0;for(int x=n;x;x-=x&-x)r+=BIT_a[x];return r;}
    int Query_b(int n){int r=0;for(int x=n;x;x-=x&-x)r+=BIT_b[x];return r;}
    int query(int l,int r){return (r+1)*Query_a(r)-Query_b(r)-l*Query_a(l-1)+Query_b(l-1);}
};
#endif
#if use_seg==1
#define builddd \
	void buildd(int num,int le,int ri)\
    {\
        if(le==ri){tre[num]=a[le];return;}\
        int mid=(le+ri)/2;\
        buildd(num*2,le,mid);\
        buildd(num*2+1,mid+1,ri);\
        tre[num]=tre[num*2]+tre[num*2+1];\
    }
struct seg_with_lazytag{
    int tre[N*4],laz[N*4],a[N],n;
    builddd
    void build(int nn,int *A)
    {
        n=nn;
        for(int x=1;x<=n;x++)
        a[x]=A[x];
        memset(tre,0,sizeof(tre));
        memset(laz,0,sizeof(laz));
        buildd(1,1,n);
    }
    seg_with_lazytag(int nn,int *A){build(nn,A);}
    void pushdown(int num,int le,int ri)
    {
    	int mid=(le+ri)/2;
        if(laz[num]!=0)tre[num*2]+=laz[num]*(mid-le+1),tre[num*2+1]+=laz[num]*(ri-mid),laz[num*2]+=laz[num],laz[num*2+1]+=laz[num],laz[num]=0;
    }
    void update(int num,int le,int ri,int x,int y,int k)
    {
        if(x<=le&&y>=ri){tre[num]+=k*(ri-le+1);laz[num]+=k;return;}
        tre[num]+=max(0ll,k*(min(ri,y)-max(le,x)+1));
        pushdown(num,le,ri);
        int mid=(le+ri)/2;
        if(x<=mid)update(num*2,le,mid,x,y,k);
        if(y>mid)update(num*2+1,mid+1,ri,x,y,k);
    }
    void update(int x,int y,int k=1){update(1,1,n,x,y,k);}
    int query(int num,int le,int ri,int x,int y)
    {
        if(x<=le&&y>=ri)return tre[num];
        pushdown(num,le,ri);
        int mid=(le+ri)/2;
        int ans=0;
        if(x<=mid)ans+=query(num*2,le,mid,x,y);
        if(y>mid)ans+=query(num*2+1,mid+1,ri,x,y);
        return ans;
    }
    int query(int x,int y){return query(1,1,n,x,y);}
};
#define update_querysum \
    void update(int num,int le,int ri,int x,int y)\
    {\
        if(le==ri){tre[num]+=y;return;}\
        int mid=(le+ri)/2;\
        if(x<=mid)update(num*2,le,mid,x,y);\
        else update(num*2+1,mid+1,ri,x,y);\
        tre[num]=tre[num*2]+tre[num*2+1];\
    }\
    void update(int x,int k=1){update(1,1,n,x,k);}\
    int query(int num,int le,int ri,int x,int y)\
    {\
        if(x<=le&&y>=ri)return tre[num];\
        int mid=(le+ri)/2;\
        int ans=0;\
        if(x<=mid)ans+=query(num*2,le,mid,x,y);\
        if(y>mid)ans+=query(num*2+1,mid+1,ri,x,y);\
        return ans;\
    }\
    int query(int x,int y){return query(1,1,n,x,y);}
struct seg_without_lazytag{
    int tre[N*4],a[N],n;
    builddd
    void build(int nn,int *A)
    {
        n=nn;
        for(int x=1;x<=n;x++)
        a[x]=A[x];
        memset(tre,0,sizeof(tre));
        buildd(1,1,n);
    }
    seg_without_lazytag(int nn,int *A){build(nn,A);}
    update_querysum
};
struct seg_without_lazytag_with_MaxMin{
    int tre[N*4],a[N],n,Max[N*4],Min[N*4];
    void buildd(int num,int le,int ri)
    {
        if(le==ri){tre[num]=Max[num]=Min[num]=a[le];return;}
        int mid=(le+ri)/2;
        buildd(num*2,le,mid);
        buildd(num*2+1,mid+1,ri);
        tre[num]=tre[num*2]+tre[num*2+1];
        Max[num]=max(Max[num*2],Max[num*2+1]);
        Min[num]=min(Min[num*2],Min[num*2+1]);
    }
    void build(int nn,int *A)
    {
        n=nn;
        for(int x=1;x<=n;x++)
        a[x]=A[x];
        memset(tre,0,sizeof(tre));
        memset(Max,0,sizeof(Max));
        memset(Min,0,sizeof(Min));
        buildd(1,1,n);
    }
    seg_without_lazytag_with_MaxMin(int nn,int *A){build(nn,A);}
    update_querysum
    int query_max(int num,int le,int ri,int x,int y)
    {
        if(x<=le&&y>=ri)return Max[num];
        int mid=(le+ri)/2;
        int ans=-10000000000;
        if(x<=mid)ans=max(ans,query_max(num*2,le,mid,x,y));
        if(y>mid)ans=max(ans,query_max(num*2+1,mid+1,ri,x,y));
        return ans;
    }
    int query_max(int x,int y){return query_max(1,1,n,x,y);}
    int query_min(int num,int le,int ri,int x,int y)
    {
        if(x<=le&&y>=ri)return Min[num];
        int mid=(le+ri)/2;
        int ans=10000000000;
        if(x<=mid)ans=min(ans,query_min(num*2,le,mid,x,y));
        if(y>mid)ans=min(ans,query_min(num*2+1,mid+1,ri,x,y));
        return ans;
    }
    int query_min(int x,int y){return query_min(1,1,n,x,y);}
};
#endif
#define exmax(a,...) (max({a,##__VA_ARGS__}))
#define exmin(a,...) (min({a,##__VA_ARGS__}))
#define mymax(x,y)  ({__typeof(x) _x=x;__typeof(y) _y=y;_x>_y?_x:_y;})
#define mymin(x,y)  ({__typeof(x) _x=x;__typeof(y) _y=y;_x<_y?_x:_y;})
#define ff(a,l,r) for(int a=l;a<=r;a++)
#define fb(a,r,l) for(int a=r;a>=l;a--)
void Init_for_all_task()
{
#if (use_C==1||use_inv==1)
init(N+10);
#endif
//111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111//
//111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111//
}
/*main-head---------------------------------------------------------------------------------------*/
//222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222//
//222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222//
/*default-var-------------------------------------------------------------------------------------*/
namespace nz{
/*namespace-head----------------------------------------------------------------------------------*/
//333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333//
//333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333//
/*var-and-func------------------------------------------------------------------------------------*/
void Main(){
struct custom_hash{static uint64_t splitmix64(uint64_t x) {x+=0x9e3779b97f4a7c15;x=(x^(x>>30))*0xbf58476d1ce4e5b9;x=(x^(x>>27))*0x94d049bb133111eb;return x^(x>>31);}size_t operator()(uint64_t x) const {static const uint64_t FIXED_RANDOM=chrono::steady_clock::now().time_since_epoch().count();return splitmix64(x+FIXED_RANDOM);}};
/*Main-head---------------------------------------------------------------------------------------*/
//444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444//
//when using um,us,gp or cc,add a hash function named custom_hash,use it like unordered_map<int,int,custom_hash>
//also,if want to hack them,https://codeforces.com/blog/entry/62393 is a good choise.
//444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444//
int n;
cin>>n;
if(n==1)ex(2);
else ex((n+2)/3);
/*Main-end----------------------------------------------------------------------------------------*/
}
/*Main-end----------------------------------------------------------------------------------------*/
}
/*namespace-end-----------------------------------------------------------------------------------*/
main()
{
    Init_for_all_task();
#if use_multiple_test_data==1
    int t;cin>>t;while(t--)
#endif
    nz::Main();
}
/*main-end----------------------------------------------------------------------------------------*/