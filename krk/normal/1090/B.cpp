#include <bits/stdc++.h>
using namespace std;

const string beg = "\\begin{thebibliography}{99}";
const string en = "\\end{thebibliography}";

map <string, string> M;
vector <string> ord;
vector <string> bibl;

int main()
{
    string lin;
    while (getline(cin, lin))
        if (lin == beg) {
            while (getline(cin, lin))
                if (lin == en) break;
                else {
                    bibl.push_back(lin);
                    int from = lin.find('{');
                    int to = lin.find('}');
                    M[lin.substr(from + 1, to - from - 1)] = lin;
                }
            break;
        } else {
            int i = 0;
            while (i + 6 <= lin.length())
                if (lin.substr(i, 6) == "\\cite{") {
                    i += 6;
                    int j = i;
                    while (lin[j] != '}') j++;
                    ord.push_back(lin.substr(i, j - i));
                    i = j;
                } else i++;
        }
    bool ok = true;
    for (int i = 0; i < ord.size() && ok; i++)
        ok = bibl[i] == M[ord[i]];
    if (ok) printf("Correct\n");
    else {
        printf("Incorrect\n");
        printf("%s\n", beg.c_str());
        for (int i = 0; i < ord.size(); i++)
            printf("%s\n", M[ord[i]].c_str());
        printf("%s\n", en.c_str());
    }
    return 0;
}