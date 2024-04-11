#include <iostream>
#include <string>
#include <set>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const long long p = 991;
long long mod = 1000000007;
const int len = 2222;

string s, beg, end;

vector < pair<long long, int> > ms;

long long p_pow[len];
long long h[len];

bool prime( int x )
{
	for ( int i = 2; i * i <= x; i++ ) if ( x % i == 0 ) return false;
	return true;
}

void gen_mod(int k)
{
	int res;
	for ( int i = 1000000000; k != 0; i++ )
	{
		if ( prime(i) == true ) k--, res = i;
	}
	mod = res;
}

void make_pows()
{
    p_pow[0]=1;
    for(int i=1;i<len;++i)
    {
        p_pow[i] = (p_pow[i-1]*p)%mod;
    }
}


void make_hashes()
{
    for(int i=0;i<s.length();++i)
    {
		long long ch = s[i] - 'a';
        h[i]=(ch*p_pow[i])%mod;
        if(i) h[i]=(h[i]+h[i-1])%mod;
    }
}

long long hash ( string st )
{
    long long res=0;
    for(int i=0;i<st.length();++i)
    {
		long long ch = st[i] - 'a';
        res+=ch*p_pow[i];
        res%=mod;
    }
    return res;
}

long long hash (int l, int r)
{
    long long res;
    res=h[r];
    if(l-1>=0)
        res-=h[l-1];

    res = (res+mod)%mod;
    return res;
}

int main()
{
	gen_mod( 17 );
    long long hb,he;
    int k=0;
    cin>>s>>beg>>end;

    make_pows();
    make_hashes();

    hb = hash ( beg );
    he = hash ( end );

    if(beg.length()>end.length())
        k=beg.length()-end.length();


    for(int i=0;i+beg.length()-1<s.length();++i)
    {
        if( (hb*p_pow[i])%mod == hash(i,i+beg.length()-1))
            for(int j=i+k;j+end.length()-1<s.length();++j)
                if((he*p_pow[j])%mod == hash(j,j+end.length()-1))
				{
                        ms.push_back(make_pair((hash(i,j+end.length()-1)*p_pow[s.length()-j-1])%mod, j + end.size() - 1 - i));
				}
    }

	sort( ms.begin(), ms.end() );
	int ans = 0;
	if ( ms.size() > 0 ) ans = 1;
	for ( int i = 1; i < ms.size(); i++ ) ans += ( ms[i - 1] != ms[i] );
	cout << ans;

    return 0;
}