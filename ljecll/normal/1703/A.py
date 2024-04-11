tc = int(input())
for i in range(tc):
    a = input()
    print("YES" if ((a[0] == 'y' or a[0] == 'Y') and (a[1] == 'e' or a[1] == 'E') and(a[2] == 's' or a[2] == 'S')) else "NO")