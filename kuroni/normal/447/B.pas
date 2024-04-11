uses math;
var n,vl,temp,maxa: int64;
    i: longint;
    A: array[1..26] of int64;
    str: ansistring;
begin
    readln(str);
    readln(n);
    for i := 1 to 26 do
    begin
        read(A[i]);
        maxa := max(maxa,A[i]);
    end;
    vl :=n*(2*length(str)+n+1)*maxa div 2;
    for i := 1 to length(str) do inc(vl,i*A[ord(str[i])-96]);
    write(vl);
end.