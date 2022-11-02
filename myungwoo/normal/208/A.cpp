#include <stdio.h>
#include <string.h>

char str[999];

int main()
{
    int i;
    char *pt;
    scanf("%s",str);
    for (i=0;str[i];i++){
        if (i > 1 && str[i-2] == 'W' && str[i-1] == 'U' && str[i] == 'B'){
            str[i-2] = str[i-1] = str[i] = ' ';
        }
    }
    for (pt=strtok(str," \n\r");pt!=NULL;pt=strtok(NULL," \n\r"))
        printf("%s ",pt);
}