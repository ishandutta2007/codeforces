#include <iostream>
#include <set>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    set<pair<int,int> >s;
    for(int i=0; i<n; ++i) {
        int a, b;
        cin >> a >> b;
        s.insert( {a,b} );
    }

    int answer = 0;
    for (auto exam : s) if (exam.second >= answer) answer = exam.second; else answer = exam.first;
    cout << answer << endl;
}