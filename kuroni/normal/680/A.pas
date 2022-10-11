uses math;

var A, B: array[1..5] of longint;
    i, j, ans: longint;

begin
    for i := 1 to 5 do read(A[i]);
    for i := 1 to 5 do for j := 1 to 5 do if A[j] = A[i] then inc(B[i]);
    for i := 1 to 5 do
    begin
        case B[i] of
            1: ans := ans;
            2: ans := max(ans,A[i]*2);
        else ans := max(ans,A[i]*3);
        end;
    end;
    write(A[1] + A[2] + A[3] + A[4] + A[5] - ans);
end.