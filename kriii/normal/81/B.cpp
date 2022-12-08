#include <stdio.h>
#include <string>
using namespace std;

char IN[300];
string S,R;

int main()
{
    int i;

    gets(IN); S = IN; S = S + " "; R = " ";
    for (i=0;i<S.length();i++){
        if (S[i] == '.'){
            if (R[0] == ' ') R = "..." + R;
            else R = "... " + R;
            i += 2;
        }
        else if (S[i] == ','){
            R = " ," + R;
        }
        else if (S[i] == ' '){}
        else{
            if ('0' <= R[0] && R[0] <= '9') R = " " + R;
            while ('0' <= S[i] && S[i] <= '9'){
                R = S[i] + R; i++;
            } i--;
        }
    }

    while (R[0] == ' ') R.erase(R.begin());
    while (*(R.end().operator--()) == ' ') R.erase(R.end().operator--());
    for (i=int(R.length())-1;i>=0;i--) printf ("%c",R[i]);

    return 0;
}