#include <iostream>
#include <string>
#include <vector>
using namespace std;

string s;
vector <string> V;

int main()
{
    getline(cin, s);
    V.push_back("");
    for (int i = 0; i < s.length(); i++)
        if (s[i] == ' ') {
                 if (V.back() != "") V.push_back("");
        } else if ('a' <= s[i] && s[i] <= 'z') V.back() += s[i];
        else if (V.back() != "") V.back() += s[i];
        else V[V.size() - 2] += s[i];
    if (V.back() != "") V.push_back(""); // sentinel
    for (int i = 0; i < V.size() - 1; i++) {
        bool lasts = false;
        for (int j = 0; j < V[i].length(); j++) {
            cout << V[i][j];
            if ('a' <= V[i][j] && V[i][j] <= 'z') lasts = false;
            else { cout << " "; lasts = true; }
        }
        if (!lasts && i + 1 < V.size() - 1) cout << " ";
    }
    cout << endl;
    return 0;
}