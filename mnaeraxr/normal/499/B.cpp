#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

#define endl '\n'
#define MP make_pair
#define DB(x) cout << #x << "=" << x << endl
#define wait system("pause")

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int MAXN = (int)1e5 + 10;

map<string,string> M;
set<string> S;

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i){
        string s1, s2;
        cin >> s1 >> s2;
        if ((int)s2.size() < (int)s1.size())
           swap(s1, s2);
        M[s1] = s1, M[s2] = s1;
    }
    for (int i = 0; i < n; ++i){
        string s;
        cin >> s;
        if (i) cout << " ";
        cout << M[s];
    }
    cout << endl;
    
    //wait;
}