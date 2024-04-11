uses math;
var n, lol, kek, i: integer;
    A: array[1..99] of integer;
begin
    read(n);
    for i := 1 to n do read(A[i]);
    for i := 1 to n do
    begin
        if A[i] = 1 then lol := i;
        if A[i] = n then kek := i;
    end;
    case n of
        2: write(1);
        3: write(2);
        else write(max(n-lol,max(n-kek,max(lol-1,kek-1))));
    end;
end.