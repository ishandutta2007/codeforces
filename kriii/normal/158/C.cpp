#include <stdio.h>
#include <string.h>
#include <vector>
#include <string>
using namespace std;

vector<string> PATH;
int T,L; char O[5],P[222];

int main()
{
    int i;

    scanf ("%d",&T); while (T--){
        scanf ("%s",O);
        if (O[0] == 'p'){
            printf ("/");
            for (i=0;i<PATH.size();i++) printf ("%s/",PATH[i].c_str());
            printf ("\n");
        }
        else{
            scanf ("%s",P); L = strlen(P);
            for (i=0;i<L;i++){
                if (P[i] == '/') P[i] = '\0';
            }

            if (P[0] == '\0'){
                PATH.clear(); i = 1;
            }
            else i = 0;

            while (i<L){
                if (P[i] == '.') PATH.pop_back();
                else PATH.push_back(P+i);
                i += strlen(P+i) + 1;
            }
        }
    }

    return 0;
}