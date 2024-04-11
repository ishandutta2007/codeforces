#include<bits/stdc++.h>
using namespace std;
long long m,x;

vector<long long> factors_m,factors_other;

vector<long long> find_divs(long long num)
{
    vector<long long> ret={};
    for(long long i=2;i*i<=num;i++)
        if(num%i==0)
        {
            ret.push_back(i);
            while(num%i==0)num=num/i;
        }
    if(num!=1)ret.push_back(num);
    return ret;
}

vector<long long> compress(vector<long long> all)
{
    sort(all.begin(),all.end());

    vector<long long> ret={};
    for(auto k:all)
        if(ret.size()==0||ret[ret.size()-1]!=k)ret.push_back(k);
    return ret;
}

long long phi(long long num,vector<long long> divs)
{
    /*
    cout<<"num= "<<num<<endl;
    cout<<"divs= ";for(auto k:divs)cout<<k<<" ";cout<<endl;
    */
    long long ret=num;
    for(auto k:divs)
        if(num%k==0)
        {
            ret=ret/k*(k-1);
            while(num%k==0)num=num/k;
        }
    assert(num==1);
    return ret;
}

vector<long long> calculate_other()
{
    vector<long long> all=find_divs(phi(m,factors_m));
    for(auto k:factors_m)all.push_back(k);

    return compress(all);
}

long long slow_mult(long long x,long long y,long long modulo)
{
    int C=10000;

    long long ret=0;

    //cout<<x<<"*"<<y<<"%"<<modulo<<"=";

    while(y)
    {
        ret=(ret+x*(y%C))%modulo;
        y=y/C;
        x=x*C%modulo;
    }

    //cout<<ret<<endl;
    return ret;
}
long long my_pow(long long a,long long b,long long modulo)
{
    if(b==0)return 1;
    long long mem=my_pow(a,b/2,modulo);

    long long ret=slow_mult(mem,mem,modulo);

    if(b%2==1)ret=slow_mult(ret,a,modulo);

    return ret;
}
long long ask(long long current_gcd)
{
    //cout<<"current_gcd "<<current_gcd<<endl;

    if(current_gcd==m)return 0;

    long long modulo=m/current_gcd;

    long long cycle=phi(modulo,factors_other);

    long long ret=cycle;

    for(auto k:factors_other)
        if(ret%k==0)
        {
            while(ret%k==0&&my_pow(x,ret/k,modulo)==1)ret=ret/k;
        }

    //cout<<"order of "<<x<<" by modulo "<<modulo<<" is "<<ret<<endl;

    return cycle/ret;
}
int main()
{
    scanf("%lld%lld",&m,&x);

    factors_m=find_divs(m);
    factors_other=calculate_other();

    //for(auto k:factors_other)cout<<k<<" ";cout<<endl;

    long long ret=1;

    for(long long d=1;d*d<=m;d++)
        if(m%d==0)
        {
            ret=ret+ask(d);
            if(d!=m/d&&d!=1)ret=ret+ask(m/d);
        }
    printf("%lld\n",ret);
    return 0;
}