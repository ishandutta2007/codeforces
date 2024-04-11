#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    string a[20]={"ABSINTH", "BEER", "BRANDY", "CHAMPAGNE", "GIN", "RUM", "SAKE", "TEQUILA", "VODKA", "WHISKEY","WINE"};
    string c;
    string d="a";
    int sum=0,z=0;
    for(int i=0;i<n;i++)
    {
        cin>>c;
        for(int j=0;j<11;j++)
            if(c==a[j] || (c[0]>='0' && c[0]<='9'))
                {
                    if(c==a[j])
                        {
                            sum++;
                            break;
                        }
                    if((c[0]=='0') || (c[1]<'8' && c[0]=='1' && c[2]==d[1]) || (c[1]==d[1]))
                        {
                            sum++;
                        }
                    break;
                }
    }
    cout<<sum;
}