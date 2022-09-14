#include<cstdio>
#include<vector>
using namespace std;
struct dat{
	long long A,B;
	bool op;
	dat(long long A,bool op,long long B):A(A),op(op),B(B){}
	void disp(){printf("%lld %c %lld\n",A,op?'+':'^',B);}
};
vector<dat>ans;
long long f(long long N){return ((N^2*N)+N)^3*N^N;}
main()
{
	long long X;
	scanf("%lld",&X);
	long long fst=X;
	int i=1;
	while(f(X*i)!=2)i+=2;
	long long T=X;
	for(int j=1;i>>j;j++)
	{
		ans.push_back(dat(T,true,T));
		T*=2;
		if(i>>j&1)
		{
			ans.push_back(dat(X,true,T));
			X+=T;
		}
	}
	ans.push_back(dat(X,true,X));
	ans.push_back(dat(X,true,2*X));
	ans.push_back(dat(X,false,2*X));
	ans.push_back(dat(X^2*X,true,X));
	ans.push_back(dat((X^2*X)+X,false,3*X));
	ans.push_back(dat((X^2*X)+X^3*X,false,X));
	for(int i=1;fst>>i;i++)
	{
		if(fst>>i&1)
		{
			ans.push_back(dat(fst,false,1LL<<i));
			fst^=1LL<<i;
		}
		if(fst!=1)ans.push_back(dat(1LL<<i,true,1LL<<i));
	}
	printf("%d\n",(int)ans.size());
	for(int i=0;i<ans.size();i++)ans[i].disp();
}