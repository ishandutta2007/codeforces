program Project1;

var
  n, i, k: LongInt;
  a: array [0..23] of LongInt;
  ItCanBe: Boolean;
  Months: array [1..60] of LongInt;

procedure ReadArray(var a: array of LongInt; N: LongInt);
begin
  For i := 0 to N-1 do
  If i < N-1 then Read(a[i]) else ReadLn(a[i]);
end;

procedure Yes(Cond: Boolean);
begin
  If Cond then WriteLn('YES') else WriteLn('NO');
end;

begin
  Months[1] := 31; //January
  Months[2] := 28; //February
  Months[3] := 31; //March
  Months[4] := 30; //April
  Months[5] := 31; //May
  Months[6] := 30; //June
  Months[7] := 31; //July
  Months[8] := 31; //August
  Months[9] := 30; //September
  Months[10] := 31; //October
  Months[11] := 30; //November
  Months[12] := 31; //December
  Months[13] := 31; //January
  Months[14] := 28; //February
  Months[15] := 31; //March
  Months[16] := 30; //April
  Months[17] := 31; //May
  Months[18] := 30; //June
  Months[19] := 31; //July
  Months[20] := 31; //August
  Months[21] := 30; //September
  Months[22] := 31; //October
  Months[23] := 30; //November
  Months[24] := 31; //December
  Months[25] := 31; //January
  Months[26] := 29; //February   In leap year
  Months[27] := 31; //March
  Months[28] := 30; //April
  Months[29] := 31; //May
  Months[30] := 30; //June
  Months[31] := 31; //July
  Months[32] := 31; //August
  Months[33] := 30; //September
  Months[34] := 31; //October
  Months[35] := 30; //November
  Months[36] := 31; //December
  Months[37] := 31; //January
  Months[38] := 28; //February
  Months[39] := 31; //March
  Months[40] := 30; //April
  Months[41] := 31; //May
  Months[42] := 30; //June
  Months[43] := 31; //July
  Months[44] := 31; //August
  Months[45] := 30; //September
  Months[46] := 31; //October
  Months[47] := 30; //November
  Months[48] := 31; //December
  Months[37] := 31; //January
  Months[38] := 28; //February
  Months[39] := 31; //March
  Months[40] := 30; //April
  Months[41] := 31; //May
  Months[42] := 30; //June
  Months[43] := 31; //July
  Months[44] := 31; //August
  Months[45] := 30; //September
  Months[46] := 31; //October
  Months[47] := 30; //November
  Months[48] := 31; //December
  Months[49] := 31; //January
  Months[50] := 28; //February
  Months[51] := 31; //March
  Months[52] := 30; //April
  Months[53] := 31; //May
  Months[54] := 30; //June
  Months[55] := 31; //July
  Months[56] := 31; //August
  Months[57] := 30; //September
  Months[58] := 31; //October
  Months[59] := 30; //November
  Months[60] := 31; //December



  ReadLn(n);
  ReadArray(a, N);
  ItCanBe:=False;

  For i := 1 to 60-n+1 do
  begin
    ItCanBe:=True;
    For k := 0 to n-1 do
    begin
      If Months[i+k] <> a[k] then
      begin
        ItCanBe := False;
        Break;
      end;
    end;
    If ItCanBe then Break;
  end;
  Yes(ItCanBe); 
end.