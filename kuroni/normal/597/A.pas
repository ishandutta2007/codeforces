var a, b, k: int64;

function MinD(a: int64): int64;
begin
    MinD := k * (a div k);
end;

function MaxD(a: int64): int64;
begin
    MaxD := k * (a div k) + k * ord(a mod k <> 0);
end;

begin
    read(k, a, b);
    if a <= 0 then a := 0 - MinD(abs(a)) else a := MaxD(a);
    if b <= 0 then b := 0 - MaxD(abs(b)) else b := MinD(b);
    write((b - a) div k + 1);
end.