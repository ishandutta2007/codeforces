#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
const int Rena = 0;
int n,m,i,counti;
int val[N],_sort[N];
map<int,int> compress;
map<int,int> re_compress;
int total_sum;
const int MOD = 998244353;

int plusi (int a, int b)
{
    long long cur = 0LL+a+b;
    if(cur < 0)
    {
        cur%=MOD;
        cur+=MOD;
    }
    return (int) (cur%MOD);
}

int mul (int a, int b)
{
    long long cur = 1LL*a*b;
    return (int) (cur%MOD);
}

int power(int base, int pow)
{
    if(pow == 0)
        return 1;
    if(pow == 1)
        return base;

    int get = power(base,pow/2);
    get = mul(get,get);
    if(pow%2 == 1)
        get = mul(get,base);
    return get;
}

int inverse(int base)
{
    return power(base,MOD-2);
}

struct fenwickTree
{
    private:
        int n;
        vector<int> bits;
    public:
        fenwickTree(int n)
        {
            this -> n = n;
            for( int i = 0; i < n; i++ )
                bits.push_back(0);
        }
        void add(int idx, int val)
        {
            for(;idx<n;idx = idx|(idx+1))
                bits[idx] = plusi(bits[idx],val);
        }
        int sum(int r)
        {
            int cur = 0;
            for(; r >= 0; r = (r&(r+1))-1 )
                cur = plusi(cur,bits[r]);
            return cur;
        }
        int sum(int l, int r)
        {
            return plusi(sum(r), -sum(l-1));
        }

        void print(int r)
        {
            for(int i = 0; i< r ;i++)
                cout<<bits[i]<<' ';
        }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    fenwickTree thisTree = fenwickTree(N);
    fenwickTree realTree = fenwickTree(N);

    cin>>n>>m;
    for(i=0;i<n;i++)
        cin>>val[i];
    sort(val,val+n);
    _sort[0] = val[0];
    compress.insert({val[0],0});
    re_compress.insert({0,val[0]});
    for(i=0;i<n;i++)
    {
        total_sum = plusi(total_sum, val[i]);
        if(i!=0 && val[i]!=val[i-1])
        {
            counti++;
            _sort[counti] = val[i];
            compress.insert({val[i],counti});
            re_compress.insert({counti,val[i]});
        }
    }
    for(i=0;i<n;i++)
    {
        val[i] = compress[val[i]];
        thisTree.add(val[i],1);
        realTree.add(val[i],re_compress[val[i]]);
        if(_sort[i]==0 && i!=0)
            _sort[i] = 1e9+10;
    }
    for(i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        int mini = 0, maxi = n;
        while(mini < maxi)
        {
            int mid = mini + maxi >> 1;
            if(mid  == mini)
            {
                if(_sort[mini] >= b)
                    maxi = mini;
                else
                    mini = maxi;
            }
            else
            {
                if(_sort[mid] >= b)
                    maxi = mid;
                else
                    mini = mid;
            }
        }
        int upper = thisTree.sum(mini, n);
        int upper_sum = realTree.sum(mini,n);
        int lower = thisTree.sum(mini-1);
        int lower_sum = realTree.sum(mini-1);
        if( a > upper)
            cout<<"0\n";
        else
        {
            int EV_upper = mul(upper-a,inverse(upper));
            EV_upper = mul(EV_upper,upper_sum);
            int EV_lower = mul(upper-a+1,inverse(upper+1));
            EV_lower = mul(EV_lower,lower_sum);
            cout<<plusi(EV_upper,EV_lower)<<"\n";
        }
    }
    return Rena;
}