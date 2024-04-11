#include <iostream>
#include <string.h>
using namespace std;
#define mp make_pair
int main()
{
    int i,x,j,white=0,black=0;
    string s;
    pair <char,int> p[]={mp('Q',9),mp('R',5),mp('B',3),mp('N',3),mp('P',1),mp('K',0)};
    for (i=0;i<8;i++)
    {
        cin >> s;
        for (x=0;x<8;x++)
        {
            if (s[x]!='.' && isupper(s[x]))
            {
                for (j=0;j<6;j++)
                {
                    if (p[j].first==s[x])
                    white+=p[j].second;
                }
            }
            else if (s[x]!='.' && islower(s[x]))
            {
                for (j=0;j<6;j++)
                {
                    if (tolower(p[j].first)==s[x])
                    black+=p[j].second;
                }
            }
        }
    }
    if (black>white)
    cout << "Black";
    else if (black==white)
    cout << "Draw";
    else
    cout << "White";
}