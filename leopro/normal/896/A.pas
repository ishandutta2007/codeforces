uses
  Math;

var
  q, i: LongInt;
  n: array [1..10] of LongInt;
  k: array [1..10] of Int64;
  Ans: Char;
  Answers: array [1..10] of Char;
const
  s1: string = 'What are you doing at the end of the world? Are you busy? Will you save us?';
  s2: string = 'What are you doing while sending "';
  s3: string = '"? Are you busy? Will you send "';
  s4: string = '"?';
  Sizes: array [0..60] of Int64 = (75, 218, 504, 1076, 2220, 4508, 9084, 18236, 36540, 73148, 146364, 292796, 585660,
  1171388, 2342844, 4685756, 9371580, 18743228, 37486524, 74973116, 149946300, 299892668, 599785404, 1199570876, 2399141820,
  4798283708, 9596567484, 19193135036, 38386270140, 76772540348, 153545080764, 307090161596, 614180323260, 1228360646588,
  2456721293244, 4913442586556, 9826885173180, 19653770346428, 39307540692924, 78615081385916, 157230162771900, 314460325543868,
  628920651087804, 1257841302175676, 2515682604351420, 5031365208702908, 10062730417405884, 20125460834811836, 40250921669623740,
  80501843339247548, 161003686678495164, 322007373356990396, 644014746713980860, 1288029493427961788, 2576058986855923644,
  2859999999999999932, 2859999999999999932, 2859999999999999932, 2859999999999999932, 2859999999999999932, 2859999999999999932);

procedure ReadString(depth: LongInt; var k: Int64);
var
  s: string;
begin
  If k = -1 then Exit;

  If depth = 0 then s := s1 else s := s2;

  While True do
  begin

    If k > Length(s) then k := k - Length(s) else
    begin
      Ans := s[k];
      k := -1;
      Break;
    end;

    If k > Sizes[min(depth-1, 60)] then
    begin
      If s = s3 then s := s4;

      If s = s2 then s := s3;

      k := k - Sizes[min(depth-1, 60)];

      end else  //If k <= Sizes[min(depth-1, 60)]
      begin
        ReadString(depth-1, k);
        Break;
      end;

  end;
end;

begin
  ReadLn(q);
  For i := 1 to q do
  begin
    Read(n[i], k[i]);
    ReadLn;
  end;
  For i := 1 to q do
  begin
    If k[i] <= Sizes[min(n[i], 60)] then
    begin
      ReadString(n[i], k[i]);
      Answers[i] := Ans;
    end else Answers[i] := '.';
  end;
  For i := 1 to q do Write(Answers[i]);
  ReadLn;
end.