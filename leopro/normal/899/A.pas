program Project1;

uses
  math;

var
  n, i, amount1, amount2, groups: LongInt;
  a: array [0..200000] of LongInt;

procedure ReadArray(var a: array of LongInt; N: LongInt);
begin
  For i := 0 to N-1 do
  If i < N-1 then Read(a[i]) else ReadLn(a[i]);
end;

begin
  ReadLn(n);
  ReadArray(a, n);
  amount1 := 0;
  amount2 := 0;
  For i := 0 to n-1 do If a[i] = 1 then amount1 := amount1 + 1 else
                                        amount2 := amount2 + 1;
  groups := min(amount1, amount2);
  If amount1 > amount2 then groups := groups + (amount1-amount2) div 3;
  WriteLn(groups);
end.