X=(2,4,3,9,5,25,7,49,11,13,17,19,23,29,31,37,41,43,47)
Y=0
for i in X:
    print(i)
    if input() == "yes":
        Y += 1
print("composite" if Y >= 2 else "prime")