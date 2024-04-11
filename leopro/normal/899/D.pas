program Project1;

uses
  math;
var
  n, shovels1, shovels2: Int64;
  Max9, sum, add1, add2, With1, WithOut, With1and2, counter: Int64;
  i: LongInt;

procedure Change(var a, b: Int64);
var
  tmp: Int64;
begin
  tmp := b;
  b := a;
  a := tmp;
end;

begin
  ReadLn(n);
  Max9 := 0;
  If n > 9 div 2 then Max9 := 9;
  If n > 99 div 2 then Max9 := 99;
  If n > 999 div 2 then Max9 := 999;
  If n > 9999 div 2 then Max9 := 9999;
  If n > 99999 div 2 then Max9 := 99999;
  If n > 999999 div 2 then Max9 := 999999;
  If n > 9999999 div 2 then Max9 := 9999999;
  If n > 99999999 div 2 then Max9 := 99999999;
  If n > 999999999 div 2 then Max9 := 999999999;
  If n > 9999999999 div 2 then Max9 := 9999999999;
  If Max9 = 0 then
  begin
    Case n of
      2: WriteLn(1);
      3: WriteLn(3);
      4: WriteLn(6);
    end;
  end else
  begin
    shovels1 := n div (Max9+1);
    shovels2 := shovels1;
    add1 := n mod (Max9+1);
    If add1 > Max9 div 2 then
    begin
      add2 := add1 - (Max9 div 2);
      add1 := add1 - add2;
    end;
    With1 := (shovels1+1) * shovels2;
    WithOut := shovels1 * shovels2;
    With1and2 := (shovels1+1) * (shovels2+1);
    If add1 < add2 then
    begin
      Change(add1, add2);
    end;

    counter := Max9 div 2 + 1;
    sum := With1 * (add1 - add2);
    sum := sum + With1and2 * add2;
    counter := counter - add1;
    sum := sum + WithOut * counter;

    WriteLn(sum);
  end;
end.