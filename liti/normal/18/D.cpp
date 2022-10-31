/* In the name of Allah */
#include <bits/stdc++.h>
#define SZ(x) ((int) x.size())
using namespace std;

const int maxL = 70;
const int limit = 1e9;
class bigNum
{
	public:
		bigNum()
		{
			for(int i =0 ; i < maxL ; i++ )  
				num[i] = 0 ; 
		}
		bigNum( string a ) 
		{
			for(int i =0 ; i < maxL ; i++ )  
				num[i] = 0 ; 
			add( a ) ; 
		}
		bigNum( const bigNum& a ) 
		{
			for(int i =0 ; i < maxL ; i++ )  
				num[i] = 0 ; 
			add( a ) ;
		}

		void add( long long val ) 
		{
			for(int i = 0 ; i < maxL ; i++ ) 
			{
				num[i] += val; 

				val = num[i] / limit;
				num[i]%= limit;
			}
		}
		void add( const bigNum& a ) 
		{
			long long val = 0 ; 
			for(int i = 0 ; i < maxL ; i++ )
			{
				num[i] += a.num[i] + val; 
				val = num[i] / limit;
				num[i] %= limit;
			}
		}
		void add( string a ) 
		{
			long long x = 1; 
			long long val = 0 ; 
			int index = 0;

			reverse( a.begin(), a.end() ) ; 
			for(int i = 0 ; i < SZ(a) ; i++ ) 
			{
				if ( x == limit ) 
				{
					num[index] = val;
					val=0 ; 
					x = 1; 
					index++;
				}

				val += x*( a[i] - '0' ) ; 
				x *= 10;
			}
			num[index] = val;
		}
		void multi( long long val ) 
		{
			long long tmp = 0; 

			for(int i = 0 ; i < maxL ; i++ )
			{
				num[i] *= val;
				num[i] += tmp;

				tmp = num[i] / limit;
				num[i] %= limit;
			}
		}
		void multi( bigNum a ) 
		{
			long long tmp;

			for(int i = maxL - 1 ; i >= 0 ; i-- )
			{
				for(int j = 0 ; j <= i ; j++ ) 
				{
					num[i] = ( j == 0 ? 0 : num[i] )  +  num[i-j]* a.num[j] ;
					tmp = num[i] / limit;
					num[i] %= limit;
					
					if( i != maxL - 1 ) 
						num[i+1] += tmp;
				}
			}

			tmp = 0 ; 
			for(int i = 0 ; i < maxL ; i++ )
			{
				num[i] += tmp;

				tmp = num[i] / limit;
				num[i] %= limit;
			}
		}
		
		bigNum div2()
		{
			long long tmp = 0 ; 
			for(int i = maxL - 1; i >= 0 ; i-- ) 
			{
				num[i] += tmp;
				if ( num[i] %2 )
					tmp = limit;
				else
					tmp = 0 ; 
				num[i]/=2;
			}

			return *this;
		}

		bool cmp( bigNum a ) 
		{
			for(int i = maxL - 1 ; i>= 0 ; i-- ) 
			{
				if ( num[i] == a.num[i] )
					continue;
				return ( num[i] >= a.num[i] ) ; 
			}
			return true;
		}


		//
		//Operators
		//

		void operator+=( const bigNum& a ) 
		{
			add(a);
		}
		void operator+=( const long long& a )
		{
			add(a);
		}
		bigNum operator+(const bigNum& a ) 
		{
			bigNum c(a);
			c.add(*this);
			return c;
		}
		bigNum operator+(const long long& a ) 
		{
			bigNum c(*this);
			c.add(a);
			return c;
		}

		void operator*=(  const bigNum& a ) 
		{
			multi(a);
		}
		bigNum operator*(const bigNum& a) 
		{
			bigNum c(*this);
			c.multi(a);
			return c;
		}
		void operator*=( const long long& a ) 
		{
			multi(a);
		}
		bigNum operator*( const long long& a )
		{
			bigNum c(*this);
			c.multi(a);
			return c;
		}
		bool operator>=( const bigNum& a ) 
		{
			return cmp( a ) ; 
		}
	
		void operator=( const bigNum& a ) 
		{
			for(int i =0 ; i < maxL ; i++ )  
				num[i] = 0 ; 
			add( a ) ;
		}
		void operator=(const long long& a) 
		{
			for(int i =0 ; i < maxL ; i++ )  
				num[i] = 0 ; 
			add( a ) ;
		}
	

		
		friend ostream& operator<< (ostream &out , const bigNum& a)
		{
			string tmp="";
			bool check = false;

			for(int i= maxL - 1; i>= 0 ; i-- ) 
			{
				tmp = "";
				long long val = a.num[i];

				for(int j =1 ; j < limit; j*=10 )
				{
					tmp += char( val % 10 + '0' ) ; 
					val/=10;
				}

				string r = "";
				for(int j = SZ(tmp) - 1  ; j >= 0 ; j-- )
				{
					if ( tmp[j] != '0' ) 
						check = true;
					if ( check ) 
						r += tmp[j];
				}

				out << r;
			}
		
			if ( check == false ) 
				out << 0 ; 
			return out;
		}


		long long num[maxL];
} ans;

const int MAX = 5000 + 10;

int t[MAX], val[MAX];
int has[MAX];
bigNum tav[MAX];

inline void calc( int s, int e ) { 
	if( e - s <= 1 ) 
		return;

	map<int,int> has;

	int bVal = -1, bS, bE;
	for(int i = s ;i < e; i++ ) 
		if( t[i] == 0 ) 
			has[ val[i] ] = i + 1 ;
		else if( has[val[i]] != 0 ) 
			if( val[i] > bVal ) { 
				bVal = val[i];
				bS = has[val[i]] - 1;
				bE = i;
			}
	if( bVal == -1 ) 
		return;
	ans += tav[bVal];
//	cout << bS << ' ' << bE << ' ' << ans << endl;
	calc(s, bS);
	calc(bE+1, e);
}

int main() { 
	tav[0] = 1;
	for(int i = 1 ; i <= 2000 ; i++) 
		tav[i] = tav[i-1]*2;
	int n;
	cin >> n;

	for(int i = 0 ; i< n ; i++ ) { 
		string s;
		int v ;
		cin >> s >> v;
		t[i] = ( s == "win" ? 0 : 1 ) ; 
		val[i] =v;
	}
	calc( 0,n ) ; 
	cout << ans << endl;
}