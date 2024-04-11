uses
  Math;

var
  la, ra, ta, lb, rb, tb: Int32;
  counta, countb, shift, spella, spellb, gcd: Int32;
  ans1, ans2, l, r: Int32;

function NOD(a, b: LongInt): LongInt;
var
  tmp: LongInt;
begin
  If a < b then
  begin
    tmp := a;
    a := b;
    b := tmp;
  end;
  If b=0 then Result:=a else Result:=NOD(a mod b, b);
end;

procedure Change(var a, b: Int32);
var
  tmp: Int32;
begin
  tmp := a;
  a := b;
  b := tmp;
end;

function Module(a, b: LongInt): LongInt;
begin
  b := abs(b);
  If a > 0 then Result := a mod b else Result := b - (-a mod b);
  If Result = b then Result := 0;
end;


begin
  ReadLn(la, ra, ta);
  ReadLn(lb, rb, tb);
  ta-=ra-la+1;
  tb-=rb-lb+1;
  counta:=ra-la+1;
  countb:=rb-lb+1;
  spella:=counta + ta;
  spellb:=countb + tb;
  gcd := NOD(spella, spellb);
  If counta < countb then
  begin
    Change(la, lb);
    Change(ra, rb);
    Change(ta, tb);
    Change(counta, countb);
    Change(spella, spellb);
  end;

  shift:=la-lb;

  shift := Module(shift, gcd);

  l := shift;
  r := min(counta+shift-1, countb-1);
  ans1 := max(0, r-l+1);
  l := 0;
  shift -= gcd;
  r := min(counta+shift-1, countb-1);
  ans2 := max(0,  r-l+1);
  WriteLn(max(ans2, ans1));
  ReadLn;
end.