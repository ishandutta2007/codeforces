N = input()
for i in range(N):
    k = i
    for j in range(N):
        print j*N+k+1,
        k = (k+1)%N
    print ''