#include <iostream>
#include <vector>
#include <cstring>
#include <string>
using namespace std;

char c[250];

vector <string> st;

void main()
{
  //  freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);

    int n;
    scanf("%d",&n);

    for (int i=0;i<n;i++)
    {
        scanf("%s",c);
        if (string(c)=="pwd")
        {
            printf("/");
            for (int i=0;i<st.size();i++)
                printf("%s/",st[i].c_str());
            printf("\n");
        }
        else if (string(c)=="cd")
        {
            char ch;
            scanf("%c",&ch);
            while (ch!='\n')
            {
                int x=scanf("%[^/\n]",c);
                if (x==0)
                    c[0]=0;
                scanf("%c",&ch);
                if (string(c)=="")
                    st.clear();
                else if (string(c)=="..")
                    st.pop_back();
                else 
                    st.push_back(string(c));
            }
        }
    }

}