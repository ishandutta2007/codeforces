#include <stdio.h>

int main(){
    printf("1999\n");
    
for (int i=0;i<1000;i++){
printf("%d 1 %d 2\n", i+1,i+1);
}
printf("2 1 2 2\n");

for (int i=2;i<1000;i++){
printf("%d 1 %d 2\n", i+1,i+1);
}
}