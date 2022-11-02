#include <iostream>
#include <string>
#include <map>
using namespace std;

int N, M;
map <string, string> A;

int main()
{
        int i;
        cin >> N >> M;
        for (i=1;i<=M;i++){
                string s, t;
                cin >> s >> t;
                A[s] = t;
        }
        for (i=1;i<=N;i++){
                string s, t;
                cin >> s;
                t = A[s];
                if (s.length() > t.length()) s = t;
                cout << s << " ";
        }
        cout << endl;
}