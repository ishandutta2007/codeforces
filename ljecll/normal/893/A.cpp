/*
PROG: cf893a
LANG: C++
    _____
  .'     '.
 /  0   0  \
|     ^     |
|  \     /  |
 \  '---'  /
  '._____.'
*/
#include <bits/stdc++.h>
 
using namespace std;
 
long long readi()
{
	long long input = 0;
	char c = ' ';
	while (c < '-')
	{
		c = getchar();
	}
	bool negative = false;
	if (c == '-')
	{
		negative = true;
		c = getchar();
	}
	while (c >= '0')
	{
		input = 10 * input + (c - '0');
		c = getchar();
	}
	if (negative)
	{
		input = -input;
	}
	return input;
}
void printi(long long output)
{
	if (output == 0)
	{
		putchar('0');
		return;
	}
	if (output < 0)
	{
		putchar('-');
		output = -output;
	}
	int aout[20];
	int ilen = 0;
	while(output)
	{
		aout[ilen] = ((output % 10));
		output /= 10;
		ilen++;
	}
	for (int i = ilen - 1; i >= 0; i--)
	{
		putchar(aout[i] + '0');
	}
	return;
}
string reads()
{
	string input = "";
	char c = ' ';
	while (c <= ' ')
	{
		c = getchar();
	}
	while (c > ' ')
	{
		input += c;
		c = getchar();
	}
	return input;
}
int sgn(long long x)
{
	if (x < 0) 
	{
		return -1;
	}
	if (x > 0) 
	{
		return 1;
	}
	return 0;
}
long long randomize(long long x)
{
	return (((1ll << 31) * rand()) + rand()) % x;
}
void yes()
{
	cout << "Yes\n";
	exit(0);
}
void no()
{
	cout << "No\n";
	exit(0);
}
void minus1()
{
	cout << "-1\n";
	exit(0);
}

#define MP make_pair
#define PB push_back
#define PF push_front
#define LB lower_bound
#define UB upper_bound
#define fi first
#define se second

const long double PI = 4.0 * atan(1.0);
const long double EPS = 0.000000000000001;

#define SINF 10007
#define INF 1000000007
#define LLINF 2696969696969696969ll
#define CO 1000037
#define MAXN 1010

long long normalize(long long x)
{
	return (((x % INF) + INF) % INF);
}

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N;
pii guys;
int arr[MAXN];

int32_t main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	srand(time(0));
	//	cout << fixed << setprecision(10);	
	//	cerr << fixed << setprecision(10);
	if (fopen("cf893a.in", "r"))
	{	
		freopen ("cf893a.in", "r", stdin);
		freopen ("cf893a.out", "w", stdout);
	}
	cin >> N;
	guys = MP(0, 1);
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		arr[i]--;
	}
	if (arr[0] == 2)
	{
		no();
	}
	for (int i = 0; i < N; i++)
	{
		//now we know who won
		if (guys.second == arr[i])
		{
			swap(guys.first, guys.second);
		}
		if (guys.first == arr[i])
		{
			//replace guys.second
			for (int j = 0; j < 3; j++)
			{
				if (j == guys.first || j == guys.second)
				{
					continue;
				}
				guys.second = j;
				break;
			}
		}
		else
		{
			no();
		}
	}
	yes();
	return 0;
}